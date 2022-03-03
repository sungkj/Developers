#include "database.h"

void DataBase::add(Employee* employee) {
	//int i;
	//for (i = 0; i < employees_.size(); i++) {
	//	if (stoi(employees_[i]->getEmployeeNum()) > stoi(employee->getEmployeeNum())) break;
	//}

	//employees_.insert(employees_.begin() + i, employee);
	employees_.push_back(employee);
	
}

void DataBase::del(vector<Employee*> target) {

}

vector<Employee*> DataBase::sch(string row, string val) {
	vector<Employee*> list;

	return list;
}

void DataBase::mod(vector<Employee*> target, string row, string val) {

vector<Employee*> DataBase::getDBList() {
	return employees_;
}

