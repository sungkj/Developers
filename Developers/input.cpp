#include "input.h"

Input::Input(string path) {
	ifs_.open(path);
}

vector<string> Input::load() {
	string str;
	
	commands_.clear();

	while (getline(ifs_, str)) {
		commands_.push_back(str);
	}

	return commands_;
}
