#pragma once

#include "jsoncpp/json/json.h"
#include "base64.h"
#include "ConnMgr.h"

#include <event2/event.h>
#include <event2/listener.h>
#include <event2/bufferevent.h>
#include <event2/thread.h>

#include <spdlog/spdlog.h>
#include <string>

class RequestMgr
{
public:
    RequestMgr(bufferevent *bev, std::string str);
    ~RequestMgr();
    void parse() const;
private:
    void Login(Json::Value data) const;
    void Register(Json::Value data) const;
    void Getlist() const;
    struct bufferevent *m_bev=nullptr;
    std::string m_reqstr;
};