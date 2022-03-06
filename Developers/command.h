#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "database.h"
#include "cmd_parser.h"

using namespace std;

class CmdExecutor
{
public:
	virtual string run() = 0;

};

class AddExecutor : public CmdExecutor
{
public:
	AddExecutor(DataBase* db, string commandStr)
		:db_(db), commandStr_(commandStr){
	}

	virtual string run(){
		AddCmdParser addCmdParser(commandStr_);
		Employee employee(addCmdParser.getEmployeeNum(), addCmdParser.getName(), addCmdParser.getCl(), addCmdParser.getPhoneNum(), addCmdParser.getBirthday(), addCmdParser.getCerti());
		db_->add(&employee);
		// delete employee;
		return "";
	}

private:
	DataBase* db_;
	string commandStr_;
};


class DelExecutor : public CmdExecutor
{
public:
	DelExecutor(DataBase* db, string commandStr)
		:db_(db), commandStr_(commandStr){

	}

	virtual string run(){
		SchCmdParser schCmdParser(commandStr_);
		vector<Employee*> employeeList = db_->sch(schCmdParser.getOption(), schCmdParser.getSchCol(), schCmdParser.getSchVal());
		string result = schCmdParser.employeeListToString(commandStr_, employeeList);
		if(!employeeList.empty())
			db_->del(employeeList);
		return result;
	}

private:
	DataBase* db_;
	string commandStr_;
};


class SchExecutor : public CmdExecutor
{
public:
	SchExecutor(DataBase* db, string commandStr_)
		:db_(db), commandStr_(commandStr_){
	}

	virtual string run(){
		SchCmdParser schCmdParser(commandStr_);
		vector<Employee*> employeeList = db_->sch(schCmdParser.getOption(), schCmdParser.getSchCol(), schCmdParser.getSchVal());
		return schCmdParser.employeeListToString(commandStr_, employeeList);
	}

private:

	DataBase* db_;
	string commandStr_;
};

class ModExecutor : public CmdExecutor
{
public:
	ModExecutor(DataBase* db, string strCommand)
		:db_(db), commandStr_(strCommand){
	}

	virtual string run(){
		SchCmdParser schCmdParser(commandStr_);
		vector<Employee*> employeeList = db_->sch(schCmdParser.getOption(), schCmdParser.getSchCol(), schCmdParser.getSchVal());
		string result = schCmdParser.employeeListToString(commandStr_, employeeList);


		if (!employeeList.empty()){
			ModCmdParser modCmdParser(commandStr_);
			db_->mod(employeeList, modCmdParser.getModCol(), modCmdParser.getModVal());
		}
		return result;
	}

private:
	DataBase* db_;
	string commandStr_;
};


class CmdManager {
public:
    CmdManager(DataBase* db);
    string execute(const string commandStr);

private:
    CmdExecutor* _getExecutor(const string commandStr);
    DataBase* db_;
   
};
