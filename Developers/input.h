#pragma once

#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Input {
public:
	virtual vector<string> load() = 0;

protected:
	vector<string> commands_;
};

class FileInput : public Input {
public:
	FileInput(const string path);
	virtual vector<string> load() override;

private:
	ifstream ifs_;
};

class FactoryInput {
public:
	static shared_ptr<Input> createFileInput(const string path) {
		return make_shared<FileInput>(path);
	}
};
