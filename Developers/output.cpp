#include "output.h"

FileOutput::FileOutput(const string path) {
	ofs_.open(path);
}

bool FileOutput::save(const vector<string> strs) {
	if (ofs_.fail()) {
		return false;
	}

	for (auto str : strs) {
		ofs_ << str << endl;
	}

	return true;
}
