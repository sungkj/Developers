#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CmdParser
{
public:
	CmdParser(string cmdStr)
	{
		splitedCmdStr_ = str_split(cmdStr, ',');
	}

protected:
	vector<string> str_split(string str, char delimiter);
	vector<string> splitedCmdStr_;
};

class AddCmdParser : public CmdParser
{
public:
	AddCmdParser(string cmdStr)
		:CmdParser(cmdStr) {}

	string getEmployeeNum() { return splitedCmdStr_[4]; }
	string getName() { return splitedCmdStr_[5]; }
	string getCl() { return splitedCmdStr_[6]; }
	string getPhoneNum() { return splitedCmdStr_[7]; };
	string getBirthday() { return splitedCmdStr_[8]; };
	string getCerti() { return splitedCmdStr_[9]; };
};

class SchCmdParser : public CmdParser
{
public:
	SchCmdParser(string cmdStr)
		:CmdParser(cmdStr) {}

	string getSchCol() { return splitedCmdStr_[4]; }
	string getSchVal() { return splitedCmdStr_[5]; }
	string getCmdCode() { return splitedCmdStr_[0]; }
	char getOption();
	string employeeListToString(string commandStr, vector<Employee*> employeeList);
private:
	bool isPrintOption() { return splitedCmdStr_[1] == "-p"; }
};

class ModCmdParser : public CmdParser
{
public:
	ModCmdParser(string cmdStr)
		:CmdParser(cmdStr) {}

	string getModCol() { return splitedCmdStr_[6]; }
	string getModVal() { return splitedCmdStr_[7]; }
};

