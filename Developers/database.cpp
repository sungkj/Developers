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

bool dbCompare(Employee* x, Employee* y) {
	int x_year = std::stoi(x->getEmployeeNum().substr(0, 2));
	int y_year = std::stoi(y->getEmployeeNum().substr(0, 2));

	if (x_year <= 22) x_year += 2000;
	else x_year += 1900;

	if (y_year <= 22) y_year += 2000;
	else y_year += 1900;

	return x_year < y_year;
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

	sort(list.begin(), list.end(), dbCompare);
	
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
