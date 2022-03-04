#include "command.h"

CmdManager::CmdManager(DataBase* db) {
	db_ = db;
}

string CmdManager::execute(const string commandStr) {
	CmdExecutor* cmdExecutor = _getExecutor(commandStr);
	string result = cmdExecutor->run();
	delete cmdExecutor;
	return result;
}

CmdExecutor* CmdManager::_getExecutor(const string commandStr){
	CmdExecutor* cmdExecutor = nullptr;
	string subStr = commandStr.substr(0, 3);
	if (subStr == "ADD")
		cmdExecutor = new AddExecutor(db_, commandStr);
	else if (subStr == "DEL")
		cmdExecutor = new DelExecutor(db_, commandStr);
	else if (subStr == "MOD")
		cmdExecutor = new ModExecutor(db_, commandStr);
	else if (subStr == "SCH")
		cmdExecutor = new SchExecutor(db_, commandStr);
	return cmdExecutor;
}

