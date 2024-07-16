#include "Server.h"
#define __DEBUG
int main(){
    Server *serv=new Server();
    serv->init();
    serv->run();
    delete serv;
    serv=nullptr;
    return 0;
}