#include "RequestMgr.h"
#include <iostream>

RequestMgr::RequestMgr(bufferevent *bev, std::string str) : 
                            m_bev(bev) , m_reqstr(str) {}

RequestMgr::~RequestMgr() {}



void RequestMgr::process() const
{   
    // spdlog::default_logger()->debug("服务器读取了一条信息 {} ", m_reqstr);

    // base64解码字符串 
    std::string str = base64_decode(m_reqstr);
    
    // 解码错误处理


    // 解析json数据
    Json::Reader reader;
    Json::Value root;
    if (!reader.parse(str, root)) {
        // std::thread::id current_thread = std::this_thread::get_id();        
        // std::cout << "Current thread ID: " << current_thread << std::endl;
        spdlog::default_logger()->error("json解析出错");	
        return;
    };
    std::string req = root["request"].asString();
    Json::Value userdata = root["userdata"];
    
    if (req == "login")            // 登录
    {   
        login(userdata);
    }
    else if (req == "signup")     // 注册 
    {
        signup(userdata);
    }
    else if (req == "upload")
    {
        spdlog::default_logger()->debug("接受到获取云列表请求");
        upload(userdata);
    }
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
    std::string name = data["username"].asString();
    std::string pwd = data["password"].asString();
    pwd = md5(pwd);

    Json::Value RetMsg;
#ifdef __DEBUG
    int getStatus = 0;
#endif
    RetMsg["status"] = 0;
    RetMsg["msg"] = "登录成功";

    // 判断是否存在，存在立刻返回
    if(!ConnMgr::getinstance()->Isexist(name)){
        // 数据库查询操作
        DBConn *conn = DBConnPool::getinstance()->getConn();
        std::string sqlstr = "select * from user_table where username =\'" 
                            + name + "\' and password =\'" + pwd + "\';";
        conn->query(sqlstr);
        
        // 数据库是否存在
        if(!conn->next()){
            RetMsg["status"] = 1;
#ifdef __DEBUG
            getStatus = 1;
#endif
            RetMsg["msg"] = "账号不存在或账号密码错误";
        }
        else
        {
            spdlog::default_logger()->info("用户{}登录", name);
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

#ifdef __DEBUG
    if(getStatus == 0)
    {
        spdlog::default_logger()->debug("返回数据未发生错误");
    }
    else
    {
        spdlog::default_logger()->error("返回出错数据");
    }
#endif    

    bufferevent_enable(m_bev, EV_WRITE);  

    // 写回数据
    bufferevent_write(m_bev, ret, strlen(ret));
    return;
}

void RequestMgr::signup(Json::Value data) const 
{
    // 获取姓名和密码
    std::string name = data["username"].asString();
    std::string pwd = data["password"].asString();
    pwd = md5(pwd);
    spdlog::default_logger()->info("用户{}请求注册", name);

    Json::Value RetMsg;
    RetMsg["status"] = 0;
    RetMsg["msg"] = "注册成功";

    // 获取数据库连接
    DBConn *conn = DBConnPool::getinstance()->getConn();
    std::string sqlstr = "select * from user_table where \'username\'=\'" 
                            + name + "\';";
    // 检验用户名是否存在
    if(conn->next()){
        RetMsg["status"] = 2;
        RetMsg["msg"] = "用户名已存在";
    } 
    else 
    {
       // 创建用户并写入数据库 
       std::string sqlstr = "insert into user_table (username, password) values (\'"
                            + name + "\', \'"+ pwd + "\');";
       int ret = conn->update(sqlstr);
       if(ret == -1)
       {
            RetMsg["status"] = 2;
            RetMsg["msg"] = "插入数据库失败";
       }
    }

    // 释放结果集并归还数据库连接
    conn->freeResSet();
    DBConnPool::getinstance()->releaseConn(conn);

    // 生成回复json
    Json::StreamWriterBuilder writer;
    std::string ret_str = Json::writeString(writer, RetMsg);
    
    // base64 编码
    ret_str=base64_encode(ret_str);
    const char *ret =ret_str.c_str();

    spdlog::default_logger()->info("返回数据:\n {}", ret);
    
    // 写回数据
    bufferevent_write(m_bev, ret, strlen(ret));
    return;
}

void RequestMgr::upload(Json::Value data) const 
{
    spdlog::default_logger()->error("上传了图片!");

}

// void RequestMgr::Getlist() const {}
