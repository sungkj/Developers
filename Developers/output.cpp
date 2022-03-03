#include "output.h"

Output::Output(string path) {
	ofs_.open(path);
}

void Output::save(vector<string> strs) {
	for (auto str : strs) {
		ofs_ << str << endl;
	}
}
