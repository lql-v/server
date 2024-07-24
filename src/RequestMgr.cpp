#include "RequestMgr.h"
#include <iostream>

RequestMgr::RequestMgr(bufferevent *bev) : m_bev(bev) {}

RequestMgr::~RequestMgr() {}

void RequestMgr::process(std::string reqstr)
{   
    // 解析json数据
    Json::Reader reader;
    Json::Value root;
    if (!reader.parse(reqstr, root)) {
        spdlog::default_logger()->error("json解析出错");	
        return;
    };
    std::string req = root["request"].asString();
    Json::Value userdata = root["userdata"];
    std::string username = root["username"].asString();

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
        upload(userdata);
    }
    else if (req == "getlist")
    {
        getlist(username);
    }
    else if (req == "getimg")
    {
        getimg(userdata);
    }
    else
    {
        spdlog::default_logger()->error("错误请求: {}", req);
    }

    // 发回数据
    Sender sender(m_bev, m_retMsg);
    sender.sendMsg();
    return;
}

// 登录处理
void RequestMgr::login(Json::Value data) 
{
    // 获取姓名和密码
    std::string name = data["username"].asString();
    std::string pwd = data["password"].asString();
    pwd = md5(pwd);

    m_retMsg["status"] = 0;
    m_retMsg["msg"] = "登录成功";

    // 判断是否存在，存在立刻返回
    if(!ConnMgr::getinstance()->Isexist(name)){
        // 数据库查询操作
        DBConn *conn = DBConnPool::getinstance()->getConn();
        std::string sqlstr = "select * from user_table where username =\'" 
                            + name + "\' and password =\'" + pwd + "\';";
        conn->query(sqlstr);
        
        // 数据库是否存在
        if(!conn->next()){
            m_retMsg["status"] = 1;
            m_retMsg["msg"] = "账号不存在或账号密码错误";
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
    
    return;
}

void RequestMgr::signup(Json::Value data) 
{
    // 获取姓名和密码
    std::string name = data["username"].asString();
    std::string pwd = data["password"].asString();
    pwd = md5(pwd);
    spdlog::default_logger()->info("用户{}请求注册", name);

    m_retMsg["status"] = 0;
    m_retMsg["msg"] = "注册成功";

    // 获取数据库连接
    DBConn *conn = DBConnPool::getinstance()->getConn();
    std::string sqlstr = "select * from user_table where \'username\'=\'" 
                            + name + "\';";
    // 检验用户名是否存在
    if(conn->next()){
        m_retMsg["status"] = 2;
        m_retMsg["msg"] = "用户名已存在";
    } 
    else 
    {
       // 创建用户并写入数据库 
       std::string sqlstr = "insert into user_table (username, password) values (\'"
                            + name + "\', \'"+ pwd + "\');";
       int ret = conn->update(sqlstr);
       if(ret == -1)
       {
            m_retMsg["status"] = 2;
            m_retMsg["msg"] = "插入数据库失败";
       }
    }

    // 释放结果集并归还数据库连接
    conn->freeResSet();
    DBConnPool::getinstance()->releaseConn(conn);
    return;
}

void RequestMgr::upload(Json::Value data) 
{
    // 回复数据
    m_retMsg["status"] = 0;

    // 提取用户数据
    std::string username = data["username"].asString();
    std::string imgname = data["imgname"].asString();
    std::string imgdata = data["imgdata"].asString();

    // 查询是否存在
    std::string sqlstr = "select id from images_table where username=\'" 
                            + username + "\' and imgname = \'" + imgname + "\';";
    // 获取数据库连接
    DBConn *conn = DBConnPool::getinstance()->getConn();
    conn->query(sqlstr);
    // 用户图片已存在
    if(conn->next())
    {
        m_retMsg["status"] = 3;
        m_retMsg["imgname"] = imgname;
    }
    // 用户图片不存在
    else
    {   
        // 插入数据库
        if(!conn->prepareUpdate(username, imgname, imgdata))
        {
            m_retMsg["status"] = 4;
            m_retMsg["imgname"] = imgname;
        }
    }
    // 释放资源
    conn->freeResSet();
    DBConnPool::getinstance()->releaseConn(conn);

    return;
}

void RequestMgr::getlist(const std::string &username)  
{

}

void RequestMgr::getimg(Json::Value data) 
{

}
