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

void ConnMgr::Add(const std::string username)
{
    m_conns.insert(username);
    return;
}

