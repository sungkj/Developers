#pragma once

#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Output {
public:
	virtual bool save(vector<string> strs) = 0;
};

class FileOutput : public Output {
public:
	FileOutput(string path);
	virtual bool save(vector<string> strs) override;

private:
	ofstream ofs_;
};

class FactoryOutput {
public:
	static shared_ptr<Output> createFileOutput(string path) {
		return make_shared<FileOutput>(path);
	}
};
