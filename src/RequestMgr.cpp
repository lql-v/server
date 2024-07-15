#include "RequestMgr.h"

RequestMgr::RequestMgr(bufferevent *bev, std::string str) : m_bev(bev) , m_reqstr(str) {}

RequestMgr::~RequestMgr() {}

void RequestMgr::parse() const
{
    spdlog::default_logger()->debug("服务器读取了一条信息 {} ", m_reqstr);
    bufferevent_enable(m_bev, EV_WRITE);
    spdlog::default_logger()->debug("服务器可写打开");

    std::string str=base64_decode(m_reqstr);
    Json::Reader reader;
    Json::Value root;
    if (!reader.parse(str, root)) {     
        spdlog::default_logger()->error("json解析出错");	
        return;
    };

    std::string req = root["request"].asString();
    Json::Value userdata = root["data"];
    if (req == "login") 
    {
        //{"request":"login"}  //eyJyZXF1ZXN0IjoibG9naW4ifQ==
        //echo -n "eyJyZXF1ZXN0IjoibG9naW4ifQ==" | nc 127.0.0.1 8080
        spdlog::default_logger()->debug("接受到登录请求");
        Login(userdata);
    }
    else if (req == "register")
    {
        spdlog::default_logger()->debug("接受到注册请求");
        Register(userdata);
    }
    else if (req == "getlist")
    {
        spdlog::default_logger()->debug("接受到获取云列表请求");
        Getlist();
    }
    else
    {
        spdlog::default_logger()->error("错误请求: {}", req);
    }
    return;
}

void RequestMgr::Login(Json::Value data) const 
{
    
    const std::string name = data["name"].asString();
    const std::string pwd = data["pwd"].asString();
    
    // 判断是否存在，存在立刻返回
    Json::Value RetMsg;
    RetMsg["status"] = 0;
    RetMsg["msg"] = "登录成功";
    if(!ConnMgr::getinstance()->Isexist(name)){
        // 数据库查询操作

        // 设置json

        // 成功则记录添加
        ConnMgr::getinstance()->Add(name);
    }
    
    // 写回json 
    Json::StreamWriterBuilder writer;
    std::string ret_str = Json::writeString(writer, RetMsg);
    ret_str=base64_encode(ret_str);
    const char *ret =ret_str.c_str();
    spdlog::default_logger()->info("返回数据:\n {}", ret);
    bufferevent_write(m_bev, ret, sizeof(ret));
    return;
}

void RequestMgr::Register(Json::Value data) const {}
void RequestMgr::Getlist() const {}