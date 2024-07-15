#include <event2/event.h>
#include <event2/listener.h>
#include <event2/bufferevent.h>
#include <event2/thread.h> // 如果需要使用多线程，可能需要引入线程支持

#include <thread>
#include <vector>
#include <iostream>

// 线程池类
class ThreadPool {
public:
    ThreadPool(size_t threads) : threads_(threads) {
        for (size_t i = 0; i < threads; ++i) {
            workers_.emplace_back([this] { run(); });
        }
    }

    ~ThreadPool() {
        // 等待所有线程结束
        for (auto& worker : workers_) {
            worker.join();
        }
    }

    // 添加任务到任务队列
    void enqueue(std::function<void()> task) {
        {
            std::unique_lock<std::mutex> lock(queue_mutex_);
            tasks_.emplace(std::move(task));
        }
        condition_.notify_one();
    }

private:
    void run() {
        while (true) {
            std::function<void()> task;
            {
                std::unique_lock<std::mutex> lock(queue_mutex_);
                condition_.wait(lock, [this] { return !tasks_.empty(); });
                task = std::move(tasks_.front());
                tasks_.pop();
            }
            task();
        }
    }

    size_t threads_;
    std::vector<std::thread> workers_;
    std::queue<std::function<void()>> tasks_;
    std::mutex queue_mutex_;
    std::condition_variable condition_;
};

// 主线程处理函数
void accept_connection(evconnlistener* listener, evutil_socket_t fd, sockaddr* address, int socklen, void* arg) {
    auto base = static_cast<event_base*>(arg);

    // 创建 bufferevent，并指定事件处理器 base
    auto bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);

    // 将 bufferevent 交给线程池处理
    ThreadPool* pool = static_cast<ThreadPool*>(event_base_get_user_data(base));
    pool->enqueue([bev] {
        // 设置 bufferevent 的读写回调函数，实现具体的业务逻辑
        bufferevent_setcb(bev,
                          [](bufferevent* bev, void* ctx) {
                              // 读回调函数
                              char buf[4096];
                              auto len = bufferevent_read(bev, buf, sizeof(buf) - 1);
                              if (len > 0) {
                                  buf[len] = '\0';
                                  std::cout << "Received data: " << buf << std::endl;
                              }
                          },
                          [](bufferevent* bev, void* ctx) {
                              // 写回调函数
                          },
                          [](bufferevent* bev, short events, void* ctx) {
                              // 事件回调函数，例如处理错误事件等
                              if (events & BEV_EVENT_ERROR) {
                                  std::cerr << "Error from bufferevent" << std::endl;
                              }
                              bufferevent_free(bev);
                          },
                          nullptr);
        bufferevent_enable(bev, EV_READ | EV_WRITE);
    });
}

int main() {
    // 初始化 libevent
    event_base* base = event_base_new();

    // 创建监听器 evconnlistener
    sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_port = htons(8080);

    evconnlistener* listener = evconnlistener_new_bind(
        base, accept_connection, base, LEV_OPT_REUSEABLE | LEV_OPT_CLOSE_ON_FREE, -1,
        reinterpret_cast<sockaddr*>(&sin), sizeof(sin));

    if (!listener) {
        std::cerr << "Failed to create listener!" << std::endl;
        return 1;
    }

    // 创建线程池，可以根据需求设置线程数量
    ThreadPool thread_pool(4); // 使用 4 个线程处理任务

    // 将线程池对象存储到 event_base 中，以便回调函数使用
    event_base_set_user_data(base, &thread_pool);

    // 进入 libevent 事件循环
    event_base_dispatch(base);

    // 释放资源
    evconnlistener_free(listener);
    event_base_free(base);

    return 0;
}

学习了单例模式、base64库的使用、json库jsoncpp的使用、
利用面向对象特性把服务端和业务端分离开来，业务端负责处理逻辑
使用base64库对客户端服务端数据进行编码解码
封装了一个请求管理类，它负责读取来自客户端的json数据并利用base64 decode函数进行解码后解析出请求
再根据请求类型执行相应的处理函数
对于每一个来到的连接，封装了一个ConnMgr类管理来自用户的连接，该类使用了设计模式中的单例模式，采用了线程安全的懒汉模式
在登录函数逻辑中会更新到ConnMgr中的连接unordered_set
服务器类重构取消连接map结构conn_
从makefile转成cmake编译
初步了解mysqlconn的使用方法