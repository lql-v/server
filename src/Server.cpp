#include "Server.h"

void read_cb(bufferevent *bev, void *arg)
{
    spdlog::default_logger()->debug("调用了read_cb");
    char buf[1024] = {0};
    std::string rec;
    while(1)
    {
        size_t size = bufferevent_read(bev, buf, sizeof(buf));
        if(size < 0)
        {
            spdlog::default_logger()->error("读取出错");	
			bufferevent_free(bev);
			exit(1);
        }
        else if (size > 0)
        {
            rec.append(buf, size);
        }
        else
        {   
            RequestMgr reqmgr(bev, rec);
            reqmgr.parse();
            return;
        }
    };
}

void write_cb(bufferevent *bev, void *arg)
{
    spdlog::default_logger()->debug("调用了write_cb");

}

void accept_cb(evconnlistener *listener, evutil_socket_t fd, sockaddr *addr, int socklen, void *arg) 
{   

	spdlog::default_logger()->info("新连接 {} 到来", fd);	
    Server *serv = static_cast<Server *>(arg);
    
    // 创建bufferevent 并指定事件处理器
    auto bev = bufferevent_socket_new(serv->m_base, fd, BEV_OPT_CLOSE_ON_FREE);
    
    // 设置读写回调函数
    serv->m_pool->enqueue([bev]
    { 
        bufferevent_setcb(bev, read_cb, write_cb, NULL, nullptr);
        bufferevent_enable(bev, EV_READ);
    });  
}

void Server::init()
{
    spdlog::set_level(spdlog::level::debug);
    spdlog::default_logger()->debug("服务器初始化中");	

    // 初始化事件集
    m_base = event_base_new();
    if(m_base == nullptr)
    {
        spdlog::default_logger()->error("libevent base 创建失败");
        exit(1);
    }

    // 初始化服务端socket
    m_sin.sin_family = AF_INET;
    m_sin.sin_addr.s_addr = htonl(INADDR_ANY);
    m_sin.sin_port = htons(8080);

    // 初始化监听器
    m_listener = evconnlistener_new_bind(m_base, accept_cb, this,
                            LEV_OPT_REUSEABLE | LEV_OPT_CLOSE_ON_FREE, -1,
                            (sockaddr*)&m_sin, sizeof(m_sin));
    if(m_listener == nullptr){
        spdlog::default_logger()->error("listener 创建失败");
        exit(1);
    }

    // 初始化线程池
    m_pool=new ThreadPool(8);

    spdlog::default_logger()->debug("服务器初始化完成");	
}

void Server::run()
{
    spdlog::default_logger()->info("服务器启动，监听端口：{}", ntohs(m_sin.sin_port));
    event_base_dispatch(m_base);
    return;
}

Server::Server() {}

Server::~Server()
{
    spdlog::default_logger()->info("服务器关闭中");	
    delete m_pool;
    m_pool=nullptr;
    evconnlistener_free(m_listener);
    event_base_free(m_base);
    spdlog::default_logger()->info("服务器关闭成功");

}


