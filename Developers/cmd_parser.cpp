#include "employee.h"
#include "cmd_parser.h"

vector<string> CmdParser::str_split(const string str, const char delimiter) {
	vector<string> splitedStr;
	string word;

	for (int i = 0; str[i] != 0; i++) {
		if (str[i] == delimiter) {
			splitedStr.push_back(word);
			word.clear();
			continue;
		}
		word.push_back(str[i]);
	}
	splitedStr.push_back(word);
	return splitedStr;
}

char SchCmdParser::getOption() {
	string str = splitedCmdStr_[IDX_OPTION];
	char result;
	if (str.size() == 2)
		result = str[1];
	else
		result = str[0];
	return result;
}

string SchCmdParser::employeeListToString(const string commandStr, const vector<Employee*> employeeList) {
	if (employeeList.size() == 0)
		return getCmdCode() + ",NONE";

	string str = "";
	if (isPrintOption()) {
		int recordSize = employeeList.size();
		if (recordSize > 5) recordSize = 5;
		for (int i = 0; i < recordSize; i++) {
			if (i != 0)
				str += "\n";
			Employee* emp = employeeList[i];
			str += getCmdCode() + "," + emp->getEmployeeNum() + "," + emp->getName() + "," + emp->getCl() + "," + emp->getPhoneNum() + "," + emp->getBirthday() + "," + emp->getCerti();
		}
	}
	else {
		str += getCmdCode() + "," + to_string(employeeList.size());
	}

	return str;
}