#include <../include/md5.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    std::cout<<md5("123456")<<std::endl;
    std::cout<<md5("456789")<<std::endl;
    return 0;
}