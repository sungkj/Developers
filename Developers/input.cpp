#include "input.h"

FileInput::FileInput(const string path) {
	ifs_.open(path);
}

vector<string> FileInput::load() {
	commands_.clear();

	if (!ifs_.fail()) {
		string str;

		while (getline(ifs_, str)) {
			commands_.push_back(str);
		}
	}

	return commands_;
}
