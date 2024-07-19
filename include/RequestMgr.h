#pragma once

#include "jsoncpp/json/json.h"
#include "base64.h"
#include "ConnMgr.h"
#include "DBConnPool.h"
#include "md5.h"
#include <event2/event.h>
#include <event2/listener.h>
#include <event2/bufferevent.h>
#include <event2/thread.h>

#include <spdlog/spdlog.h>
#include <string>

/**
 * @class 请求管理
 * @brief 在读回调函数中处理来自客户的请求，并执行相应函数
 */
class RequestMgr
{
public:
    /**
     * @brief 构造函数
     * @param[in] bev 事件集
     * @param[in] str 来自客户的未解析字符串
     */
    RequestMgr(bufferevent *bev, std::string str);

    ~RequestMgr();
    /**
     * @fn 处理
     * @brief 解析并处理用户的请求
     */
    void process() const;
private:
    /**
     * @brief 处理登录请求
     * @param[in] data 已解析用户附带数据集
     */
    void login(Json::Value data) const;
    /**
     * @brief 处理注册请求
     * @param[in] data 已解析用户附带数据集
     */
    void signup(Json::Value data) const;

    // void getlist() const;
    struct bufferevent *m_bev=nullptr;          // 事件集
    std::string m_reqstr;                       // 客户端传输的字符串
};