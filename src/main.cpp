#pragma once
#include "Server.h"

int main(){
    Server *serv=new Server();
    serv->init();
    serv->run();
    delete serv;
    serv=nullptr;
    return 0;
}