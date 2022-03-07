#include "output.h"

FileOutput::FileOutput(const string path) {
	ofs_.open(path);
}

bool FileOutput::write(const string str) {
	if (ofs_.fail()) {
		return false;
	}

	ofs_ << str << endl;

	return true;
}
