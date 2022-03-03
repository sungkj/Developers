#pragma once

#include <iostream>
#include "input.h"
#include "output.h"

using namespace std;

class EmployeeManager {
public:
    void readInput(Input* input);
    void excute();
    void writeOutput(Output* output);

private:
    vector<string> commandStrs_;
    vector<string> outputStrs_;
};
