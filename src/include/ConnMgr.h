#pragma once
#include<mutex>
#include<unordered_map>

/**
 * @class 连接管理类
 * @brief 记录用户的连接状态 单例模式
 */
class ConnMgr {
public:
	static ConnMgr* getinstance();
    void Add(std::string username, const int fd);
    ConnMgr(const ConnMgr&) = delete;
    ConnMgr & operator= (const ConnMgr &obj) = delete;
    bool Isexist(const std::string username) const; 
    void Remove(const int fd);
private:
    std::unordered_map<std::string, int> m_conns; 
    static ConnMgr* m_instance;
	static std::mutex m_mutex;
	ConnMgr(){};
};

