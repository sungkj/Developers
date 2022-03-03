#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "database.h"

using namespace std;

class Command {
public:
    Command(string command);
    void execute();
    string getOutputText();

private:
    DataBase* db_;
    string outputText_;
};
