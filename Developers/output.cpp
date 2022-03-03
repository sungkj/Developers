#include "output.h"

Output::Output(string path) {
	ofs_.open(path);
}

bool Output::save(vector<string> strs) {
	if (ofs_.fail()) {
		return false;
	}

	for (auto str : strs) {
		ofs_ << str << endl;
	}

	return true;
}
