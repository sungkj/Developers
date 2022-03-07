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
	string getComponent(int idx){
		if (idx >= splitedCmdStr_.size()) {
			throw out_of_range("커맨드 정보를 정상적으로 가져올 수 없습니다.");
		}
		return splitedCmdStr_[idx];
	}
};

class AddCmdParser : public CmdParser
{
public:
	AddCmdParser(const string cmdStr)
		:CmdParser(cmdStr) {}

	string getEmployeeNum() { return getComponent(IDX_EMPLOYEE_NUM); }
	string getName() { return getComponent(IDX_NAME); }
	string getCl() { return getComponent(IDX_CL); }
	string getPhoneNum() { return getComponent(IDX_PHONE_NUM); };
	string getBirthday() { return getComponent(IDX_BIRTH_DAY); };
	string getCerti() { return getComponent(IDX_CERTI); };

private:
	const int IDX_EMPLOYEE_NUM = 4;
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

	string getSchCol() { return getComponent(IDX_SCH_COL); }
	string getSchVal() { return getComponent(IDX_SCH_VAL); }
	string getCmdCode() { return getComponent(IDX_CMD_CODE); }
	char getOption();
	string employeeListToString(const string commandStr, const vector<Employee*> employeeList);
		
private:
	bool isPrintOption() { return getComponent(IDX_PRINT_OPTION) == "-p"; }
	
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

	string getModCol() { return getComponent(IDX_MOD_COL); }
	string getModVal() { return getComponent(IDX_MOD_VAL); }

private:
	const int IDX_MOD_COL = 6;
	const int IDX_MOD_VAL = 7;
};

