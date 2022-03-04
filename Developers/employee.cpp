
#include "employee.h"

Employee::Employee(string employeeNum, string name, string cl, string phoneNum, string birthday, string certi) :
    cl_(cl), certi_(certi) {
	int employeeNumYear = stoi(employeeNum.substr(0, 2));
	if (employeeNumYear < 69) {
		employeeNum_ = stoi(employeeNum) + 2000000000U;
	}
	else {
		employeeNum_ = stoi(employeeNum) + 1900000000U;
	}

	size_t pos = name.find(' ');
	firstName_ = name.substr(0, pos);
	lastName_ = name.substr(pos + 1);

	size_t pos1 = phoneNum.find('-');
	size_t pos2 = phoneNum.find('-', pos1 + 1);
	middlePhoneNum_ = phoneNum.substr(pos1 + 1, pos2 - pos1 - 1);
	lastPhoneNum_ = phoneNum.substr(pos2 + 1);

	birthdayYear_ = birthday.substr(0, 4);
	birthdayMonth_ = birthday.substr(4, 2);
	birthdayDate_ = birthday.substr(6);
}

string Employee::getEmployeeNum() {
	return to_string(employeeNum_).substr(2);
}

string Employee::getName() {
	return firstName_ + " " + lastName_;
}

string Employee::getCl() {
	return cl_;
}

string Employee::getPhoneNum() {
	return "010-" + middlePhoneNum_ + "-" + lastPhoneNum_;
}

string Employee::getBirthday() {
	return birthdayYear_ + birthdayMonth_ + birthdayDate_;
}

string Employee::getCerti() {
	return certi_;
}

string Employee::getFirstName() {
	return firstName_;
}

string Employee::getLastName() {	
	return lastName_;
}

string Employee::getMiddlePhoneNum() {
	return middlePhoneNum_;
}

string Employee::getLastPhoneNum() {
	return lastPhoneNum_;
}

string Employee::getBirthdayYear() {
	return birthdayYear_;
}

string Employee::getBirthdayMonth() {
	return birthdayMonth_;
}

string Employee::getBirthdayDate() {
	return birthdayDate_;
}

void Employee::setName(string name) {
	size_t pos = name.find(' ');
	firstName_ = name.substr(0, pos);
	lastName_ = name.substr(pos + 1);
}

void Employee::setCl(string cl) {
	cl_ = cl;
}

void Employee::setPhoneNum(string phoneNum) {
	size_t pos1 = phoneNum.find('-');
	size_t pos2 = phoneNum.find('-', pos1 + 1);
	middlePhoneNum_ = phoneNum.substr(pos1 + 1, pos2 - pos1 - 1);
	lastPhoneNum_ = phoneNum.substr(pos2 + 1);

}

void Employee::setBirthday(string birthday) {
	birthdayYear_ = birthday.substr(0, 4);
	birthdayMonth_ = birthday.substr(4, 2);
	birthdayDate_ = birthday.substr(6);

}

void Employee::setCerti(string certi) {
	certi_ = certi;
}
