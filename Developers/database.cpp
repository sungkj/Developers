#include "database.h"
#include <string>
#include <algorithm>

using namespace std;

void DataBase::add(Employee* employee) {
	int i;
	Employee* empl = new Employee(*employee);
	if (empl == nullptr) {
		cout << "Error : Failed to alloc!" << endl;
		return;
	}

	for (i = 0; i < employees_.size(); i++) {
		if (*empl < *employees_[i]) {
			break;
		}
		if (*empl == *employees_[i]) {
			cout << "ERROR : Exist same employee number" << endl;
			return;
		}
	}

	employees_.insert(employees_.begin() + i, empl);
}

void DataBase::del(vector<Employee*> targets) {
	Employee* empl;
	for (auto target : targets) {
		for (int i = 0; i < employees_.size(); i++) {
			empl = employees_[i];
			if (*target == *empl) {
				employees_.erase(employees_.begin() + i);
				delete empl;
				break;
			}
		}
	}
}

vector<Employee*> DataBase::sch(char option, string col, string val) {
	vector<Employee*> list;
	string employeeInfo;

	for (auto employees : employees_) {
		employeeInfo = employees->getInfo(option, col);
		if (employeeInfo == "error_code") break;
		if (employeeInfo == val) list.push_back(employees);
	}

	return list;
}

void DataBase::mod(vector<Employee*> targets, string column, string val) {
	for (auto target : targets) {
		for (auto employee : employees_) {
			if (*target == *employee) {
				employee->setInfo(column, val);
			}
		}
	}
}
