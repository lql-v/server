#include "Sender.h"

Sender::Sender(struct bufferevent *bev, Json::Value msg) :
                m_bev(bev), m_msg(msg) {}

Sender::~Sender() {}

void Sender::sendMsg()
{
    // 生成回复json
    Json::StreamWriterBuilder writer;
    std::string str = Json::writeString(writer, m_msg);
    
    // base64 编码
    str=base64_encode(str);
    const char *ret =str.c_str();

    // 写回数据
    bufferevent_write(m_bev, ret, strlen(ret));
}