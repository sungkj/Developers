#include "database.h"
#include <string>


void modifyInfo(Employee* employee, string column, string val) {
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
	else {
		cout << "ERROR : invalid column" << endl;
	}
}

void DataBase::add(Employee* employee) {
	//int i;
	//for (i = 0; i < employees_.size(); i++) {
	//	if (stoi(employees_[i]->getEmployeeNum()) > stoi(employee->getEmployeeNum())) break;
	//}

	//employees_.insert(employees_.begin() + i, employee);
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

vector<Employee*> DataBase::sch(string row, string val) {
	vector<Employee*> list;

	return list;
}

void DataBase::mod(vector<Employee*> target, string row, string val) {
	for (int i = 0; i < target.size(); i++) {
		for (int j = 0; j < employees_.size(); j++) {
			if (target[i]->getEmployeeNum().compare(employees_[j]->getEmployeeNum()) == 0) {
				modifyInfo(employees_[j], row, val);
				break;
			}
		}
	}
}

vector<Employee*> DataBase::getDBList() {
	return employees_;
}

