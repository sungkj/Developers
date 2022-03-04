#include "input.h"

Input::Input(string path) {
	ifs_.open(path);
}

vector<string> Input::load() {
	commands_.clear();

	if (!ifs_.fail()) {
		string str;


		while (getline(ifs_, str)) {
			commands_.push_back(str);
		}
	}

	return commands_;
}
