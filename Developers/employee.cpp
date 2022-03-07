#include "employee.h"

Employee::Employee(const EmployeeInfo employeeInfo) :
	employeeNum_(employeeInfo.employeeNum), name_(employeeInfo.name), cl_(employeeInfo.cl), phoneNum_(employeeInfo.phoneNum), birthday_(employeeInfo.birthday), certi_(employeeInfo.certi) {
}

string Employee::getEmployeeNum() const {
	return employeeNum_.get();
}

string Employee::getName() const {
	return name_.getName();
}

string Employee::getCl() const {
	return cl_;
}

string Employee::getPhoneNum() const {
	return phoneNum_.getPhoneNum();
}

string Employee::getBirthday() const {
	return birthday_.get();
}

string Employee::getCerti() const {
	return certi_;
}

string Employee::getFirstName() const {
	return name_.getFirstName();
}

string Employee::getLastName() const {
	return name_.getLastName();
}

string Employee::getMiddlePhoneNum() const {
	return phoneNum_.getMiddlePhoneNum();
}

string Employee::getLastPhoneNum() const {
	return phoneNum_.getLastPhoneNum();
}

string Employee::getBirthdayYear() const {
	return birthday_.getYear();
}

string Employee::getBirthdayMonth() const {
	return birthday_.getMonth();
}

string Employee::getBirthdayDate() const {
	return birthday_.getDate();
}

void Employee::setName(const string name) {
	name_.setName(name);
}

void Employee::setCl(const string cl) {
	cl_ = cl;
}

void Employee::setPhoneNum(const string phoneNum) {
	phoneNum_.setPhoneNum(phoneNum);
}

void Employee::setBirthday(const string birthday) {
	birthday_.set(birthday);
}

void Employee::setCerti(const string certi) {
	certi_ = certi;
}
