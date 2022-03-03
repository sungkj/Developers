#include "database.h"
#include <string>

void DataBase::add(Employee* employee) {
	employees_.push_back(employee);
}

void DataBase::del(vector<Employee*> target) {
	for (int i = 0; i < target.size(); i++) {
		for (int j = 0; j < employees_.size(); j++) {
			if (target[i]->getEmployeeNum().compare(employees_[j]->getEmployeeNum()) == 0) {
				employees_.erase(employees_.begin() + j);
				break;
			}
		}
	}
}

vector<Employee*> DataBase::sch(char option, string col, string val) {
	vector<Employee*> list;

	for (auto employees : employees_) {
		if (col == "employeeNum") {
			if (val == employees->getEmployeeNum()) list.push_back(employees);
		}
		else if (col == "name") {
			if (option == ' ') {
				if (val == employees->getName()) list.push_back(employees);
			}
			else if (option == 'f') {
				if (val == employees->getFirstName()) list.push_back(employees);
			}
			else if (option == 'l') {
				if (val == employees->getLastName()) list.push_back(employees);
			}
		}
		else if (col == "cl") {
			if (val == employees->getCl()) list.push_back(employees);
		}
		else if (col == "phoneNum") {
			if (option == ' ') {
				if (val == employees->getPhoneNum()) list.push_back(employees);
			}
			else if (option == 'm') {
				if (val == employees->getMiddlePhoneNum()) list.push_back(employees);
			}
			else if (option == 'l') {
				if (val == employees->getLastPhoneNum()) list.push_back(employees);
			}
		}
		else if (col == "birthday") {
			if (option == ' ') {
				if (val == employees->getBirthday()) list.push_back(employees);
			}
			else if (option == 'y') {
				if (val == employees->getBirthdayYear()) list.push_back(employees);
			}
			else if (option == 'm') {
				if (val == employees->getBirthdayMonth()) list.push_back(employees);
			}
			else if (option == 'd') {
				if (val == employees->getBirthdayDate()) list.push_back(employees);
			}
		}
		else if (col == "certi") {
			if (val == employees->getCerti()) list.push_back(employees);
		}
	}

	return list;

}

void DataBase::mod(vector<Employee*> target, string row, string val) {

}

vector<Employee*> DataBase::getDBList() {
	return employees_;
}
