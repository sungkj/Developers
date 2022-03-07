#include "input.h"

FileInput::FileInput(const string path) {
	ifs_.open(path);
}

string FileInput::read() {
	string str;
	if (!ifs_.fail()) {
		getline(ifs_, str);
	}
	
	return str;
}
