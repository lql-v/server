#include "ConnMgr.h"

ConnMgr* ConnMgr::m_instance=nullptr;
std::mutex ConnMgr::m_mutex;

ConnMgr* ConnMgr::getinstance()
{
    if (m_instance == nullptr)
    {
        m_mutex.lock();
        if (m_instance == nullptr)
        {
            m_instance = new ConnMgr();
        }
        m_mutex.unlock();
    }
    return m_instance;
}

bool ConnMgr::Isexist(const std::string username) const 
{
    return m_conns.find(username)!=m_conns.end();
}

void ConnMgr::Add(const std::string username, const int fd)
{
    m_conns["username"] = fd;
    return;
}

void ConnMgr::Remove(const int fd)
{
    for(auto it = m_conns.begin(); it != m_conns.end(); ++it)
    {
        if (it->second == fd) {
            m_conns.erase(it);  // 删除当前迭代器指向的键值对
            return;  // 找到并删除后可以退出循环
        }
    }
    return;
}

