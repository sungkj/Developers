#pragma once

#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Input {
public:
	Input(string path);
	vector<string> load();

private:
	ifstream ifs_;
	vector<string> commands_;
};