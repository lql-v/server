#include "Server.h"


struct magic
{
    int size;
    char arr[8]= "7777777";
};

// 读回调函数
void read_cb(bufferevent *bev, void *arg)
{   
#ifdef __DEBUG
    struct evbuffer *evbuf = bufferevent_get_input(bev);
    size_t len = evbuffer_get_length(evbuf);
    if(len < 12) return;
    
    std::string rec;
    while(len > 0)
    {   
        spdlog::default_logger()->debug("读, {} ", len);
        char buf[4096];
        int size = (len<=4096) ? len : 4096;
        // 读取并丢弃数据
        bufferevent_read(bev, buf, size);
        rec.append(buf, size);
        len -= size;
    }
    // 检查后四位是否是特殊符号
    if( (rec.substr(rec.length()-4)) == "/EOF")
    {
        rec.erase(rec.length() - 4);
    }
    // evbuffer_free(evbuf);
    // 创建需求管理器
    spdlog::default_logger()->debug("接受到消息大小：{}", rec.size());
    RequestMgr reqmgr(bev, rec);
    // 解析需求并执行相应函数
    reqmgr.process();
    return;
#else 
    char buf[4096] = {0};
    std::string rec;
    // 读取来自用户的信息
    while(1)
    {   
        size_t size = bufferevent_read(bev, buf, sizeof(buf));
        if(size < 0) // 读取大小小于0 出错
        {
            spdlog::default_logger()->error("读取出错");	
			bufferevent_free(bev);
			exit(1);
        }
        else if (size > 0) // 仍然有数据
        {
            rec.append(buf, size);
        }
        else // 读取数据量为0 读取完成
        {   
            // 创建需求管理器
            spdlog::default_logger()->debug("接受到消息大小：{}", rec.size());
            RequestMgr reqmgr(bev, rec);
            // 解析需求并执行相应函数
            reqmgr.process();
            return;
        }
    };
#endif
}

#ifdef __DEBUG
// 写回调函数
void write_cb(bufferevent *bev, void *arg)
{
    spdlog::default_logger()->debug("调用了write_cb");
}
#endif

// 接受连接回调函数
void accept_cb(evconnlistener *listener, evutil_socket_t fd, 
                sockaddr *addr, int socklen, void *arg) 
{   
    // 设置socket缓冲区大小
    int nRecvBufLen = 128 * 1024; //设置为K
    setsockopt(fd, SOL_SOCKET, SO_RCVBUF, (const char*)&nRecvBufLen, sizeof(int));

    char ip[32] = {0};
    evutil_inet_ntop(AF_INET, addr, ip, sizeof(ip)-1);
	spdlog::default_logger()->info("ip:{} fd:{} 客户端连接 ", ip, fd);	

    // 获取事件处理器
    Server *serv = static_cast<Server*>(arg);
    // 创建bufferevent 并指定事件处理器
    struct bufferevent *bev = bufferevent_socket_new(serv->m_base, fd, BEV_OPT_CLOSE_ON_FREE);
   
    bufferevent_set_max_single_read(bev, 128*1024);

    // spdlog::default_logger()->error(bufferevent_set_max_single_read(bev, INT_MAX));

    // 设置读写回调函数
    serv->m_pool->enqueue([bev]
    {   
#ifdef __DEBUG
        bufferevent_setcb(bev, read_cb, write_cb, NULL, nullptr);
#else 
        bufferevent_setcb(bev, read_cb, NULL, NULL, nullptr);
#endif
        bufferevent_enable(bev, EV_READ);
    });  
}

// 服务器初始化
void Server::init()
{   

    // 设置日志级别
#ifdef __DEBUG
    spdlog::set_level(spdlog::level::debug);
#else
    spdlog::set_level(spdlog::level::info);
#endif

    // window初始化socket库
#ifdef _WIN32
    WSADATA wsdata;
    if(WSAStartup(MAKEWORD(2,2), &wsdata) != 0)
    {
        spdlog::default_logger()->error("WSAStartup失败");
        exit(1);
    }
#endif

    // 初始化事件集
    m_base = event_base_new();
    if(m_base == nullptr)
    {
        spdlog::default_logger()->error("libevent base 创建失败");
        exit(1);
    }

    // 初始化服务端socket
    m_sin.sin_family = AF_INET;
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
}

// 服务器运行
void Server::run()
{
    init();
    spdlog::default_logger()->info("服务器启动，监听端口：{}", ntohs(m_sin.sin_port));
    event_base_dispatch(m_base);
    return;
}

Server::Server() {}

Server::~Server()
{
    if(m_pool != nullptr)
    {
        delete m_pool;
        m_pool = nullptr;
    }    
    if(m_listener != nullptr)
    {
        evconnlistener_free(m_listener);
        m_listener = nullptr;
    }

    if(m_base !=nullptr)
    {
        event_base_free(m_base);
        m_base = nullptr;
    }
    spdlog::default_logger()->info("服务器关闭");
#ifdef _WIN32
    WSACleanup();
#endif
}


