#pragma once

#include <iostream>

using namespace std;

class Employee {
public:
    Employee(/*id, name, ...*/);
    string getName();
    string getFirstName();
    string getLastName();


private:
    string id;
    string name;
    string cl;
    string number;
    string birth;
    string certi;
};
