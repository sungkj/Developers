#pragma once

#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Output {
public:
	virtual bool write(const string str) = 0;
};

class FileOutput : public Output {
public:
	FileOutput(const string path);
	virtual bool write(const string str) override;

private:
	ofstream ofs_;
};

class FactoryOutput {
public:
	static shared_ptr<Output> createFileOutput(const string path) {
		return make_shared<FileOutput>(path);
	}
};
