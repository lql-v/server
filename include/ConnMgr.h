#pragma once
#include<mutex>
#include<unordered_set>

class ConnMgr {
public:
	static ConnMgr* getinstance();
    void Add(std::string username);
    ConnMgr(const ConnMgr&) = delete;
    ConnMgr & operator= (const ConnMgr &obj) = delete;
    bool Isexist(const std::string username) const;
private:
    std::unordered_set<std::string> m_conns; 
    static ConnMgr* m_instance;
	static std::mutex m_mutex;
	ConnMgr(){};
    
};

