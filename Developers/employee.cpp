#include "employee.h"

Employee::Employee(string employeeNum, string name, string cl, string phoneNum, string birthday, string certi) :
    employeeNum_(employeeNum), name_(name), cl_(cl), phoneNum_(phoneNum), birthday_(birthday), certi_(certi) {
}

string Employee::getEmployeeNum() {
	return employeeNum_.get();
}

string Employee::getName() {
	return name_.getName();
}

string Employee::getCl() {
	return cl_;
}

string Employee::getPhoneNum() {
	return phoneNum_.getPhoneNum();
}

string Employee::getBirthday() {
	return birthday_.get();
}

string Employee::getCerti() {
	return certi_;
}

string Employee::getFirstName() {
	return name_.getFirstName();
}

string Employee::getLastName() {	
	return name_.getLastName();
}

string Employee::getMiddlePhoneNum() {
	return phoneNum_.getMiddlePhoneNum();
}

string Employee::getLastPhoneNum() {
	return phoneNum_.getLastPhoneNum();
}

string Employee::getBirthdayYear() {
	return birthday_.getYear();
}

string Employee::getBirthdayMonth() {
	return birthday_.getMonth();
}

string Employee::getBirthdayDate() {
	return birthday_.getDate();
}

void Employee::setName(string name) {
	name_.setName(name);
}

void Employee::setCl(string cl) {
	cl_ = cl;
}

void Employee::setPhoneNum(string phoneNum) {
	phoneNum_.setPhoneNum(phoneNum);
}

void Employee::setBirthday(string birthday) {
	birthday_.set(birthday);
}

void Employee::setCerti(string certi) {
	certi_ = certi;
}
