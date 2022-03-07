#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "database.h"
#include "cmd_parser.h"
#include "cmd_executor.h"

using namespace std;

class CmdManager {
public:
    CmdManager(DataBase* db);
    string execute(const string commandStr);

private:
    CmdExecutor* _getExecutor(const string commandStr);
    DataBase* db_;
   
};
