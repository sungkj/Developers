#include "command.h"

Command::Command(DataBase* db) {
	db_ = db;
}

string Command::execute(const string commandStr) {
	// db 함수를 이용하여 명령어 수행하고 출력값 return
	CommandExecutor* commandExecutor = _getExecutor(commandStr);
	string result = commandExecutor->run();
	delete commandExecutor;
	return result;
}

CommandExecutor* Command::_getExecutor(const string commandStr){
	CommandExecutor* commandExecutor = nullptr;
	string subStr = commandStr.substr(0, 3);
	if (subStr == "ADD")
		commandExecutor = new AddExecutor(db_, commandStr);
	else if (subStr == "DEL")
		commandExecutor = new DelExecutor(db_, commandStr);
	else if (subStr == "MOD")
		commandExecutor = new ModExecutor(db_, commandStr);
	else if (subStr == "SCH")
		commandExecutor = new SchExecutor(db_, commandStr);
	return commandExecutor;
}

