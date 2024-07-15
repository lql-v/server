#pragma once
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

class MySQLConn
{
public:
    MySQLConn();
    ~MySQLConn();
    bool Connect();
    bool Query();
    bool Next();
    bool Update();
    bool transaction();
    bool commit();
    bool rollback();

private:
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;
};