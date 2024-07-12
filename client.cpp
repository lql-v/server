#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <netdb.h>

const int PORT = 8080;
const char* SERVER_IP = "127.0.0.1"; // localhost

int main() {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    // 创建 socket 文件描述符
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Socket creation error" << std::endl;
        return -1;
    }

    // 设定服务器地址和端口信息
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // 将 IPv4 字符串地址转换为网络地址
    if (inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        return -1;
    }

    // 连接到服务器
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Connection Failed" << std::endl;
        return -1;
    }

    // 发送消息到服务器
    const char* hello = "Hello from client";
    send(sock, hello, strlen(hello), 0);
    std::cout << "Message sent to server" << std::endl;

    // 从服务器接收响应
    valread = read(sock, buffer, 1024);
    std::cout << "Server response: " << buffer << std::endl;

    return 0;
}
