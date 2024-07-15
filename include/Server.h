#pragma once

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
class Server
{
public: 
    friend void accept_cb(evconnlistener *listener, evutil_socket_t fd, sockaddr *addr, int socklen, void *arg);
    Server();
    ~Server();
    void init();
    void run();
private:
  
    struct event_base *m_base=nullptr;
    ThreadPool *m_pool=nullptr;
    struct sockaddr_in m_sin={0};
    struct evconnlistener *m_listener=nullptr;
};

