#include "database.h"
#include <string>
#include <algorithm>

using namespace std;

void DataBase::add(Employee* employee) {
	Employee* empl = new Employee(*employee);
	if (empl == nullptr) {
		cout << "Error : Failed to alloc!" << endl;
		return;
	}

	employees_.push_back(empl);
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

bool comparePtrToNode(Employee* a, Employee* b) {
	return (*a < *b); 
}


vector<Employee*> DataBase::sch(char option, string col, string val) {
	vector<Employee*> list;
	string employeeInfo;

	for (auto employees : employees_) {
		employeeInfo = employees->getInfo(option, col);
		if (employeeInfo == "error_code") break;
		if (employeeInfo == val) list.push_back(employees);
	}

	if (list.size() > 1) sort(list.begin(), list.end(), comparePtrToNode);
	
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
