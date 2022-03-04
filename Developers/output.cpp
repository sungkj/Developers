#include "output.h"

FileOutput::FileOutput(string path) {
	ofs_.open(path);
}

bool FileOutput::save(vector<string> strs) {
	if (ofs_.fail()) {
		return false;
	}

	for (auto str : strs) {
		ofs_ << str << endl;
	}

	return true;
}
