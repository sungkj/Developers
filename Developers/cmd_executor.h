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
		:db_(db), commandStr_(commandStr) {
	}

	virtual string run();

private:
	DataBase* db_;
	string commandStr_;
};


class DelExecutor : public CmdExecutor
{
public:
	DelExecutor(DataBase* db, string commandStr)
		:db_(db), commandStr_(commandStr) {

	}

	virtual string run();

private:
	DataBase* db_;
	string commandStr_;
};


class SchExecutor : public CmdExecutor
{
public:
	SchExecutor(DataBase* db, string commandStr_)
		:db_(db), commandStr_(commandStr_) {
	}

	virtual string run();

private:

	DataBase* db_;
	string commandStr_;
};

class ModExecutor : public CmdExecutor
{
public:
	ModExecutor(DataBase* db, string strCommand)
		:db_(db), commandStr_(strCommand) {
	}

	virtual string run();

private:
	DataBase* db_;
	string commandStr_;
};