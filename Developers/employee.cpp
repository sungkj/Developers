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

string Employee::toString() const {
	return getEmployeeNum() + "," + getName() + "," + getCl() + "," + getPhoneNum() + "," + getBirthday() + "," + getCerti();
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

string Employee::getInfo(char option, string col) {
	if (col == "employeeNum") {
		return getEmployeeNum();
	}
	else if (col == "name") {
		if (option == ' ') {
			return getName();
		}
		else if (option == 'f') {
			return getFirstName();
		}
		else if (option == 'l') {
			return getLastName();
		}
	}
	else if (col == "cl") {
		return getCl();
	}
	else if (col == "phoneNum") {
		if (option == ' ') {
			return getPhoneNum();
		}
		else if (option == 'm') {
			return getMiddlePhoneNum();
		}
		else if (option == 'l') {
			return getLastPhoneNum();
		}
	}
	else if (col == "birthday") {
		if (option == ' ') {
			return getBirthday();
		}
		else if (option == 'y') {
			return getBirthdayYear();
		}
		else if (option == 'm') {
			return getBirthdayMonth();
		}
		else if (option == 'd') {
			return getBirthdayDate();
		}
	}
	else if (col == "certi") {
		return getCerti();
	}

	return "error_code";
}
