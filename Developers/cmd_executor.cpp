#include "cmd_executor.h"

string AddExecutor::run() {
	AddCmdParser addCmdParser(commandStr_);
	struct EmployeeInfo employeeInfo;
	employeeInfo.employeeNum = addCmdParser.getEmployeeNum();
	employeeInfo.name = addCmdParser.getName();
	employeeInfo.cl = addCmdParser.getCl();
	employeeInfo.phoneNum = addCmdParser.getPhoneNum();
	employeeInfo.birthday = addCmdParser.getBirthday();
	employeeInfo.certi = addCmdParser.getCerti();
	Employee employee(employeeInfo);
	db_->add(&employee);
	// delete employee;
	return "";
}

string DelExecutor::run() {
	SchCmdParser schCmdParser(commandStr_);
	vector<Employee*> employeeList = db_->sch(schCmdParser.getOption(), schCmdParser.getSchCol(), schCmdParser.getSchVal());
	string result = schCmdParser.employeeListToString(commandStr_, employeeList);
	if (!employeeList.empty())
		db_->del(employeeList);
	return result;
}

string SchExecutor::run() {
	SchCmdParser schCmdParser(commandStr_);
	vector<Employee*> employeeList = db_->sch(schCmdParser.getOption(), schCmdParser.getSchCol(), schCmdParser.getSchVal());
	return schCmdParser.employeeListToString(commandStr_, employeeList);
}

string ModExecutor::run() {
	SchCmdParser schCmdParser(commandStr_);
	vector<Employee*> employeeList = db_->sch(schCmdParser.getOption(), schCmdParser.getSchCol(), schCmdParser.getSchVal());
	string result = schCmdParser.employeeListToString(commandStr_, employeeList);

	if (!employeeList.empty()) {
		ModCmdParser modCmdParser(commandStr_);
		db_->mod(employeeList, modCmdParser.getModCol(), modCmdParser.getModVal());
	}
	return result;
}