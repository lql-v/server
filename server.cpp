#include <iostream>
#include <event2/event.h>
#include <event2/listener.h>
#include <event2/bufferevent.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <spdlog/spdlog.h> 
#define PORT 8080
#define BUFFSIZE 1024
void read_cb(bufferevent *bev, void *arg)
{	
	// int fd = *(int *)arg;
	char buf[BUFFSIZE]={0};
	std::string rec;
	while(1){
		size_t ret = bufferevent_read(bev, buf, sizeof(buf));
		if (ret < 0)
		{
			spdlog::default_logger()->error("读取出错");	
			// std::cout << "读取出错" << std::endl;
			bufferevent_free(bev);
			return;
		}
		else if (ret > 0) 
		{
			rec.append(buf, ret);
			// 读取json
		}
		else
		{
			spdlog::default_logger()->debug("服务器读取了一条信息 {}", rec);	

			break;
		}
	}
	//switch(根据json做相应的相应){}
	// 登录
	// 注册
	// 上传图片
	// 获取云列表
	// 刷新云列表
	// 双击展示获取某张数据图片
}

void write_cb(bufferevent *bev, void *arg)
{

}

// void event_cb(bufferevent *bev, short what, void *arg)
// {

// }

void accept_callback(evconnlistener *listener, evutil_socket_t fd, sockaddr *addr, int socklen, void *arg) 
{
	spdlog::default_logger()->info("新连接 {} 到来", fd);	

    // 创建一个事件处理器
    struct event_base *base = evconnlistener_get_base(listener);
    struct bufferevent *bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);

    // 设置读写回调函数
    bufferevent_setcb(bev, read_cb, write_cb, NULL, NULL);
    bufferevent_enable(bev, EV_READ | EV_WRITE);
}

int main()
{	
	// 初始化日志库
	spdlog::set_level(spdlog::level::debug);

    // 创建事件集合
    struct event_base *base = event_base_new();
    if (base == nullptr) {
		spdlog::default_logger()->error("libevent base 创建失败");
        return 1;
    }

	// 初始化服务器ip
	struct sockaddr_in sin= {0} ;
	sin.sin_addr.s_addr=inet_addr("127.0.0.1");
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);

    // 创建监听器
    struct evconnlistener *listener = evconnlistener_new_bind(base, accept_callback, base,
                                       LEV_OPT_CLOSE_ON_FREE | LEV_OPT_REUSEABLE ,
                                       -1, (sockaddr*)&sin, sizeof(sin));
    if (listener == nullptr) {
		spdlog::default_logger()->error("listener 创建失败");
        return 1;
    }

	spdlog::default_logger()->info("服务器启动，监听端口： {}", PORT);	
	
    // 进入事件循环监听事件
    event_base_dispatch(base);

    // 清理资源
    evconnlistener_free(listener);
    event_base_free(base);
    return 0;
}