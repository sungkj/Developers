#pragma once

#include <iostream>
#include <vector>
#include "employee.h"

using namespace std;

class DataBase {
    void ADD();
    void DEL();
    void SCH();
    void MOD();

private:
    vector<Employee*>empolyees;
};
