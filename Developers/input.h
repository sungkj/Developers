#pragma once

#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Input {
public:
	virtual string read() = 0;
};

class FileInput : public Input {
public:
	FileInput(const string path);
	virtual string read() override;

private:
	ifstream ifs_;
};

class FactoryInput {
public:
	static shared_ptr<Input> createFileInput(const string path) {
		return make_shared<FileInput>(path);
	}
};
