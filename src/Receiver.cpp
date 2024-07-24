#include "Receiver.h"

Receiver::Receiver(struct bufferevent *bev) : m_bev(bev) {}

Receiver::~Receiver() {}

// 获取输入信息
bool Receiver::getInput()
{   
    // 获取输入缓冲区
    m_evbuf = bufferevent_get_input(m_bev);

    // 获取已有数据大小
    size_t len = evbuffer_get_length(m_evbuf);

    // 数据不足
    if(len < 8) return false;

    // 获取包头信息
    char head[9];
    evbuffer_copyout(m_evbuf, head, 8);
    // 检查魔数是否正确，不正确丢弃
    if(!checkHeader(head))
    {
        evbuffer_drain(m_evbuf, len);
        return false;
    }
    // 检查长度是否符合可读（数据足够才可读）
    if(!checkLen(head, len))
    {
        return false;
    }

    // 丢弃包头
    evbuffer_drain(m_evbuf, 8);
    len -= 8;
    // 循环读空数据
    while(len > 0)
    {
        char buf[4096];
        int size = (len <= 4096) ? len : 4096;
        // 读取并丢弃数据
        bufferevent_read(m_bev, buf, size);
        m_str.append(buf, size);
        len -= size;
    }
    return true;
}

// 返回解码的用户数据
std::string Receiver::getData()
{
    return base64_decode(m_str);
}

// 检查包头的魔数信息
bool Receiver::checkHeader(const char *header)
{
    uint32_t magic = ntohl(*(uint32_t *)header);
    return magic == 17171717;
}

// 检查包头长度是否符合可读
bool Receiver::checkLen(const char *header, size_t len)
{   
    // 用户数据长度
    uint32_t datalen = ntohl(*(uint32_t *)(header + 4));
    if(datalen + 8 > len)
    {   
        // 调整低水位
        bufferevent_setwatermark(m_bev, EV_READ, len, 0);
        return false;
    }
    // 恢复低水位
    bufferevent_setwatermark(m_bev, EV_READ, 0, 0);
    return true;
}
