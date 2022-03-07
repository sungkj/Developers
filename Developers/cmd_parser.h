#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CmdParser
{
public:
	CmdParser(const string cmdStr)
	{
		splitedCmdStr_ = str_split(cmdStr, ',');
	}

protected:
	vector<string> str_split(const string str, const char delimiter);
	vector<string> splitedCmdStr_;
};

class AddCmdParser : public CmdParser
{
public:
	AddCmdParser(const string cmdStr)
		:CmdParser(cmdStr) {}

	string getEmployeeNum() { return splitedCmdStr_[IDX_EMPOLYEE_NUM]; }
	string getName() { return splitedCmdStr_[IDX_NAME]; }
	string getCl() { return splitedCmdStr_[IDX_CL]; }
	string getPhoneNum() { return splitedCmdStr_[IDX_PHONE_NUM]; };
	string getBirthday() { return splitedCmdStr_[IDX_BIRTH_DAY]; };
	string getCerti() { return splitedCmdStr_[IDX_CERTI]; };

private:
	const int IDX_EMPOLYEE_NUM = 4;
	const int IDX_NAME = 5;
	const int IDX_CL = 6;
	const int IDX_PHONE_NUM = 7;
	const int IDX_BIRTH_DAY= 8;
	const int IDX_CERTI = 9;
};

class SchCmdParser : public CmdParser
{
public:
	SchCmdParser(const string cmdStr)
		:CmdParser(cmdStr) {}

	string getSchCol() { return splitedCmdStr_[IDX_SCH_COL]; }
	string getSchVal() { return splitedCmdStr_[IDX_SCH_VAL]; }
	string getCmdCode() { return splitedCmdStr_[IDX_CMD_CODE]; }
	char getOption();
	string employeeListToString(const string commandStr, const vector<Employee*> employeeList);
		
private:
	bool isPrintOption() { return splitedCmdStr_[IDX_PRINT_OPTION] == "-p"; }
	
	const int IDX_CMD_CODE = 0;
	const int IDX_PRINT_OPTION = 1;
	const int IDX_OPTION = 2;
	const int IDX_SCH_COL = 4;
	const int IDX_SCH_VAL = 5;

};

class ModCmdParser : public CmdParser
{
public:
	ModCmdParser(const string cmdStr)
		:CmdParser(cmdStr) {}

	string getModCol() { return splitedCmdStr_[IDX_MOD_COL]; }
	string getModVal() { return splitedCmdStr_[IDX_MOD_VAL]; }

private:
	const int IDX_MOD_COL = 6;
	const int IDX_MOD_VAL = 7;
};

