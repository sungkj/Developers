#pragma once

#include <iostream>
#include <vector>
#include "employee.h"

using namespace std;

class DataBase {
public:
    void add(Employee* employee);
    void del(vector<Employee*> target);
    vector<Employee*> sch(char option, string col, string val);
    void mod(vector<Employee*> target, string row, string val);
    vector<Employee*> getDBList();

private:
    vector<Employee*> employees_;  // vector 말고 sorting 되는걸로?
};