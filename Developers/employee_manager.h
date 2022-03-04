#pragma once

#include <iostream>
#include "input.h"
#include "output.h"
#include "command.h"
#include "database.h"

using namespace std;

class EmployeeManager {
public:
    void readInput(shared_ptr<Input> inputPtr);
    void execute();
    void writeOutput(shared_ptr<Output> outputPtr);

private:
    vector<string> commandStrs_;
    vector<string> outputStrs_;
};
