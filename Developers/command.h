#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "database.h"

using namespace std;

class CommandExecutor
{
public:
	virtual string run() = 0;
protected:
	vector<string> str_split(string str, char delimiter){
		vector<string> splitedStr;
		string word;

		for (int i = 0; str[i] != 0; i++){
			if (str[i] == delimiter){
				splitedStr.push_back(word);
				word.clear();
				continue;
			}
			word.push_back(str[i]);
		}
		splitedStr.push_back(word);
		return splitedStr;
	}

	Employee* _getEmployee(string commandStr){
		vector<string> splitedStr = str_split(commandStr, ',');
		return new Employee(splitedStr[4], splitedStr[5], splitedStr[6], splitedStr[7], splitedStr[8], splitedStr[9]);
	}

	string _employeeListToString(string commandStr, vector<Employee*> employeeList){
		if (employeeList.size() == 0)
			return "NONE";

		string str = "";
		if (_isPrintOption(commandStr)){
			for (int i = 0; i < employeeList.size(); i++){
				if (i != 0)
					str += "\n";
				Employee* emp = employeeList[i];
				str += _getCmdCode(commandStr) + "," + emp->getEmployeeNum() + "," + emp->getName() + "," + emp->getCl() + "," + emp->getPhoneNum() + "," + emp->getBirthday() + "," + emp->getCerti();
			}
		}
		else{
			str += _getCmdCode(commandStr) + "," + to_string(employeeList.size());
		}
		
		return str;
	}

	bool _isPrintOption(string commandStr) { return commandStr.substr(4, 2) == "-p"; }
	string _getCol(string commandStr) { return str_split(commandStr, ',')[4]; }
	string _getVal(string commandStr) { return str_split(commandStr, ',')[5]; }
	char _getOption(string commandStr) { 
		string str =  str_split(commandStr, ',')[2];
		char result;
		if (str.size() == 2)
			result = str[1];
		else
			result = str[0];
		return result;
	}
	string _getCmdCode(string commandStr) { return commandStr.substr(0, 3); }

};



class AddExecutor : public CommandExecutor
{
public:
	AddExecutor(DataBase* db, string commandStr)
		:db_(db), commandStr_(commandStr){
	}

	virtual string run(){
		Employee* employee = _getEmployee(commandStr_);
		db_->add(employee);
		// delete employee;
		return "";
	}

private:
	DataBase* db_;
	string commandStr_;
};


class DelExecutor : public CommandExecutor
{
public:
	DelExecutor(DataBase* db, string commandStr)
		:db_(db), commandStr_(commandStr){

	}

	virtual string run(){
		vector<Employee*> employeeList = db_->sch(_getOption(commandStr_), _getCol(commandStr_), _getVal(commandStr_));
		string result = _employeeListToString(commandStr_, employeeList);
		db_->del(employeeList);
		return result;
		/*to do : employList 메모리 해제??*/
	}

private:
	DataBase* db_;
	string commandStr_;
};


class SchExecutor : public CommandExecutor
{
public:
	SchExecutor(DataBase* db, string commandStr_)
		:db_(db), commandStr_(commandStr_){
	}

	virtual string run(){
		vector<Employee*> employeeList = db_->sch(_getOption(commandStr_), _getCol(commandStr_), _getVal(commandStr_));
		return _employeeListToString(commandStr_, employeeList);
		/*to do : employList 메모리 해제??*/
	}

private:

	DataBase* db_;
	string commandStr_;
};

class ModExecutor : public CommandExecutor
{
public:
	ModExecutor(DataBase* db, string strCommand)
		:db_(db), commandStr_(strCommand){
	}

	virtual string run(){
		string col = _getCol(commandStr_);
		string val = _getVal(commandStr_);
		vector<Employee*> employeeList = db_->sch(_getOption(commandStr_), col, val);
		string result = _employeeListToString(commandStr_, employeeList);
		db_->mod(employeeList, col, val);
		return result;
		/*to do : employList 메모리 해제??*/
	}

private:
	DataBase* db_;
	string commandStr_;
};


class Command {
public:
    Command(DataBase* db);
    string execute(const string command);

private:
    CommandExecutor* _getExecutor(const string commandStr);
    DataBase* db_;
   
};
