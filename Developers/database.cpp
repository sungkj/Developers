#include "database.h"
#include <string>
#include <algorithm>

using namespace std;

void DataBase::add(Employee* employee) {
	employees_.push_back(employee);
}

void DataBase::del(vector<Employee*> targets) {
	for (auto target : targets) {
		for (int i = 0; i < employees_.size(); i++) {
			if (target->getEmployeeNum().compare(employees_[i]->getEmployeeNum()) == 0) {
				employees_.erase(employees_.begin() + i);
				break;
			}
		}
	}
}

bool comparePtrToNode(Employee* a, Employee* b) {
	return (*a < *b); 
}

string DataBase::getEmployeeInfo(Employee* employee, char option, string col)
{
	if (col == "employeeNum") {
		return employee->getEmployeeNum();
	}
	else if (col == "name") {
		if (option == ' ') {
			return employee->getName();
		}
		else if (option == 'f') {
			return employee->getFirstName();
		}
		else if (option == 'l') {
			return employee->getLastName();
		}
	}
	else if (col == "cl") {
		return employee->getCl();
	}
	else if (col == "phoneNum") {
		if (option == ' ') {
			return employee->getPhoneNum();
		}
		else if (option == 'm') {
			return employee->getMiddlePhoneNum();
		}
		else if (option == 'l') {
			return employee->getLastPhoneNum();
		}
	}
	else if (col == "birthday") {
		if (option == ' ') {
			return employee->getBirthday();
		}
		else if (option == 'y') {
			return employee->getBirthdayYear();
		}
		else if (option == 'm') {
			return employee->getBirthdayMonth();
		}
		else if (option == 'd') {
			return employee->getBirthdayDate();
		}
	}
	else if (col == "certi") {
		return employee->getCerti();
	}

	return "error_code";
}

vector<Employee*> DataBase::sch(char option, string col, string val) {
	vector<Employee*> list;
	string employeeInfo;

	for (auto employees : employees_) {
		employeeInfo = getEmployeeInfo(employees, option, col);
		if (employeeInfo == "error_code") break;
		if (employeeInfo == val) list.push_back(employees);
	}

	if (list.size() > 1) sort(list.begin(), list.end(), comparePtrToNode);
	
	return list;
}

void DataBase::mod(vector<Employee*> targets, string column, string val) {
	for (auto target : targets) {
		for (auto employee : employees_) {
			if (target->getEmployeeNum().compare(employee->getEmployeeNum()) == 0) {
				if (column.compare("name") == 0) {
					employee->setName(val);
				}
				else if (column.compare("birthday") == 0) {
					employee->setBirthday(val);
				}
				else if (column.compare("cl") == 0) {
					employee->setCl(val);
				}
				else if (column.compare("certi") == 0) {
					employee->setCerti(val);
				}
				else if (column.compare("phoneNum") == 0) {
					employee->setPhoneNum(val);
				}
				else {
					cout << "ERROR : invalid column" << endl;
				}
				break;
			}
		}
	}
}

vector<Employee*> DataBase::getDBList() {
	return employees_;
}
