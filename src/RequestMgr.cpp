#include "RequestMgr.h"

RequestMgr::RequestMgr(bufferevent *bev, std::string str) : 
                            m_bev(bev) , m_reqstr(str) {}

RequestMgr::~RequestMgr() {}

void RequestMgr::process() const
{
    spdlog::default_logger()->debug("服务器读取了一条信息 {} ", m_reqstr);

    // base64解码字符串
    std::string str=base64_decode(m_reqstr);
    
    // 解析json数据
    Json::Reader reader;
    Json::Value root;
    if (!reader.parse(str, root)) {
        spdlog::default_logger()->error("json解析出错");	
        return;
    };
    std::string req = root["request"].asString();
    Json::Value userdata = root["data"];
    
    bufferevent_enable(m_bev, EV_WRITE);
    spdlog::default_logger()->debug("服务器可写打开");    
    

    if (req == "login")            // 登录
    {   
        //echo -n "eyJyZXF1ZXN0IjoibG9naW4ifQ==" | nc 127.0.0.1 8080
        spdlog::default_logger()->debug("接受到登录请求");
        login(userdata);
    }
    else if (req == "signup")     // 注册 
    {
        spdlog::default_logger()->debug("接受到注册请求");
        signup(userdata);
    }
    // else if (req == "getlist")
    // {
    //     spdlog::default_logger()->debug("接受到获取云列表请求");
    //     getlist();
    // }
    else
    {
        spdlog::default_logger()->error("错误请求: {}", req);
    }
    return;
}

// 登录处理
void RequestMgr::login(Json::Value data) const 
{
    // 获取姓名和密码
    std::string name = data["name"].asString();
    std::string pwd = data["pwd"].asString();
    
    // 判断是否存在，存在立刻返回
    Json::Value RetMsg;
    RetMsg["status"] = 0;
    RetMsg["msg"] = "登录成功";
    if(!ConnMgr::getinstance()->Isexist(name)){
        // 数据库查询操作
        DBConn *conn = DBConnPool::getinstance()->getConn();
        conn->query("select name,password from user_table;");
        
        std::string nameInDB;
        std::string pwdInDB;
        // 判断是否存在
        while(conn->next()){
            nameInDB = value("name");
            pwdInDB = value("password");
        }

        // 设置json
        if(nameInDB != name || pwdInDB != pwd)
        {
            RetMsg["status"] = 1;
            RetMsg["msg"] = "账号或密码错误";
        }

        // 成功则记录添加
        ConnMgr::getinstance()->Add(name);

        // 释放结果集并归还数据库连接
        conn->freeResSet();
        DBConnPool::getinstance()->releaseConn(conn);
    }
    
    // 生成回复json
    Json::StreamWriterBuilder writer;
    std::string ret_str = Json::writeString(writer, RetMsg);
    
    // base64 编码
    ret_str=base64_encode(ret_str);
    const char *ret =ret_str.c_str();

    spdlog::default_logger()->info("返回数据:\n {}", ret);
    
    // 写回数据
    bufferevent_write(m_bev, ret, sizeof(ret));
    return;
}

void RequestMgr::signup(Json::Value data) const {}
// void RequestMgr::Getlist() const {}