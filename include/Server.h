#pragma once

#include "RequestMgr.h"
#include "ThreadPool.h"
#include <event2/event.h>
#include <event2/listener.h>
#include <event2/bufferevent.h>
#include <event2/thread.h>

#include <spdlog/spdlog.h>

#include <arpa/inet.h>
#include <thread>
#include <string>

/**
 * @class 服务器
 */
class Server
{
    friend void accept_cb(evconnlistener *listener, evutil_socket_t fd, 
                            sockaddr *addr, int socklen, void *arg);
public: 
    Server();
    ~Server();
    /**
     * @brief 服务器对象初始化
     */
    void init();
    /**
     * @brief 服务器对象运行
     */   
    void run();
private:
    struct event_base *m_base=nullptr;              // 事件集合
    ThreadPool *m_pool=nullptr;                     // 线程池指针
    struct sockaddr_in m_sin={0};                   // 服务端socket
    struct evconnlistener *m_listener=nullptr;      // 监听器指针
};

/**
 * @brief 写回调函数
 * @param[in] bev 事件
 * @param[in] arg 接收回调函数所传参数
 */
void write_cb(bufferevent *bev, void *arg);

/**
 * @brief 读回调函数
 * @param[in] bev 事件
 * @param[in] arg 接收回调函数所传参数
 */
void read_cb(bufferevent *bev, void *arg);

/**
 * @brief 接受回调函数
 * @param[in] listener 监听器
 * @param[in] evutil_socket_t socket描述符
 * @param[in] addr socket结构指针
 * @param[in] socklen socket长度
 * @param[in] arg 将要传给读写回调函数的参数
 */
void accept_cb(evconnlistener *listener, evutil_socket_t fd, sockaddr *addr, int socklen, void *arg);
