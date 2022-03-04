#pragma once

#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Output {
public:
	Output(string path);
	bool save(vector<string> strs);

private:
	ofstream ofs_;
};