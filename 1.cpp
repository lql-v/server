struct evbuffer *evbuf = bufferevent_get_input(bev);
    size_t len = evbuffer_get_length(evbuf);
    if(len % 4096 == 0) return;
    std::string rec;
    while(len > 0)
    {   
        spdlog::default_logger()->debug("读, {} ", len);
        char buf[4096];
        int size = (len<=4096) ? len : 4096;
        // 读取并丢弃数据
        bufferevent_read(bev, buf, size);
        rec.append(buf, size);
        len -= size;
    }
    // 检查后四位是否是特殊符号
    if( (rec.substr(rec.length()-4)) == "/EOF")
    {
        rec.erase(rec.length() - 4);
    }
    // evbuffer_free(evbuf);
    // 创建需求管理器
    spdlog::default_logger()->debug("接受到消息大小：{}", rec.size());
    RequestMgr reqmgr(bev, rec);
    // 解析需求并执行相应函数
    reqmgr.process();
    return;
    // 可行


QByteArray MainWindow::getInput(QString request)
{
    // 获取用户输入数据
    QString name = ui->lineEditUserName->text();
    QString pwd = ui->lineEditPassword->text();

    // 检查是否填写
    if(name == "" || pwd == "")
    {
        MsgBox *box = new MsgBox(this, "请正确填写账号密码", "错误");
        box->exec();
        return "";
    }
    // 创建Json数据
    QJsonObject userdata;
    userdata.insert("password", pwd);
    userdata.insert("username", name);
    QJsonObject msg;
    msg.insert("request", request);
    msg.insert("userdata", userdata);

    // 创建 QJsonDocument 对象，用于处理 JSON 数据
    QJsonDocument jsonDocument(msg);

    // 将 QJsonDocument 转换为 QByteArray
    QByteArray byteArray = jsonDocument.toJson();

    // 将 QByteArray 转换为 base64 编码
    QByteArray codeStr = byteArray.toBase64().constData();

    return codeStr;
}


















// 获取输入缓冲区
    struct evbuffer *evbuf = bufferevent_get_input(bev);
    // 读取缓冲区有数据的大小
    size_t len = evbuffer_get_length(evbuf);
    // 数据量小于8 不对劲直接返回
    if(len < 8) return;

    // 读出前8个字节
    char head[9];
    evbuffer_copyout(evbuf, head, 8);
    uint32_t magic = ntohl(*(uint32_t *)head);
    uint32_t datalen = ntohl(*(uint32_t *)(head + 4));
    
    // 魔数比较
        // 接受数据还不足以处理
        if(datalen + 8 > len)
        {   
            bufferevent_setwatermark(bev, EV_READ, len , 0);
            return;
        }
        // 接受数据足够
        else
        {        
            evbuffer_drain(evbuf, 8);
            len -= 8;
            bufferevent_setwatermark(bev, EV_READ, 0, 0);
            std::string rec;
            while(len > 0)
            {   
                char buf[4096];
                int size = (len <= 4096) ? len : 4096;
                // 读取并丢弃数据
                bufferevent_read(bev, buf, size);
                rec.append(buf, size);
                len -= size;
            }
            // 创建需求管理器
            spdlog::default_logger()->debug("接受到消息大小：{}", rec.size());
            RequestMgr reqmgr(bev, rec);
            // 解析需求并执行相应函数
            reqmgr.process();
            return;
        }