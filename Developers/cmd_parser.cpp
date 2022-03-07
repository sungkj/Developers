#include "employee.h"
#include "cmd_parser.h"

#ifndef MAX
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#endif
vector<string> CmdParser::str_split(const string str, const char delimiter) {
	vector<string> splitedStrs;
	string word;

	for (int i = 0; str[i] != 0; i++) {
		if (str[i] == delimiter) {
			splitedStrs.push_back(word);
			word.clear();
			continue;
		}
		word.push_back(str[i]);
	}
	splitedStrs.push_back(word);
	return splitedStrs;
}

char SchCmdParser::getOption() {
	string str = getComponent(IDX_OPTION);
	char result;
	if (str.size() == 2)
		result = str[1];
	else
		result = str[0];
	return result;
}

string SchCmdParser::employeeListToString(const string commandStr, const vector<Employee*> employeeList) {
	
	const int MAX_RECORD_SIZE = 5;
	
	if (employeeList.size() == 0)
		return getCmdCode() + ",NONE";

	string str = "";
	if (isPrintOption()) {
		int recordSize = MAX(employeeList.size(), MAX_RECORD_SIZE);
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