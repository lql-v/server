#include "../include/DBConn.h"

int main()
{
    vector<DBConn*> cs(10);
    for(int i=0; i<10; ++i)
    {
        cs[i] = new DBConn();
        cs[i]->connect("mgr","123456","server","localhost",3306);
    }
    return 0;
}