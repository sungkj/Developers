#pragma once

#include <iostream>
#include <string>

using namespace std;

class EmployeeNum {
public:
	EmployeeNum(string employeeNum) {
		int employeeNumYear = stoi(employeeNum.substr(0, 2));
		if (employeeNumYear < minimumYear_) {
			employeeNum_ = stoi(employeeNum) + offset2000_;
		}
		else {
			employeeNum_ = stoi(employeeNum) + offset1900_;
		}
	}
	string get() {
		return to_string(employeeNum_).substr(2);
	}
	bool operator<(const EmployeeNum& employeeNum) {
		return this->employeeNum_ < employeeNum.employeeNum_;
	}
	bool operator==(const EmployeeNum& employeeNum) {
		return this->employeeNum_ == employeeNum.employeeNum_;
	}

private:
	const int minimumYear_ = 69;
	const unsigned int offset1900_ = 1900000000U;
	const unsigned int offset2000_ = 2000000000U;
	unsigned int employeeNum_;
};

class Name {
public:
	Name(string name) {
		setName(name);
	}
	string getName() {
		return firstName_ + " " + lastName_;
	}
	string getFirstName() {
		return firstName_;
	}
	string getLastName() {
		return lastName_;
	}
	void setName(string name) {
		size_t pos = name.find(' ');
		firstName_ = name.substr(0, pos);
		lastName_ = name.substr(pos + 1);
	}

private:
	string firstName_;
	string lastName_;
};

class PhoneNumber {
public:
	PhoneNumber(string phoneNum) {
		setPhoneNum(phoneNum);
	}
	string getPhoneNum() {
		return firstPhoneNum_ + "-" + middlePhoneNum_ + "-" + lastPhoneNum_;
	}
	string getMiddlePhoneNum() {
		return middlePhoneNum_;
	}
	string getLastPhoneNum() {
		return lastPhoneNum_;
	}
	void setPhoneNum(string phoneNum) {
		size_t pos1 = phoneNum.find('-');
		size_t pos2 = phoneNum.find('-', pos1 + 1);
		middlePhoneNum_ = phoneNum.substr(pos1 + 1, pos2 - pos1 - 1);
		lastPhoneNum_ = phoneNum.substr(pos2 + 1);
	}

private:
	const string firstPhoneNum_{ "010" };
	string middlePhoneNum_;
	string lastPhoneNum_;
};

class Date {
public:
	Date(string dateStr) {
		set(dateStr);
	}
	string get() {
		return year_ + month_ + date_;
	}
	string getYear() {
		return year_;
	}
	string getMonth() {
		return month_;
	}
	string getDate() {
		return date_;
	}
	void set(string dateStr) {
		year_ = dateStr.substr(0, 4);
		month_ = dateStr.substr(4, 2);
		date_ = dateStr.substr(6);
	}

private:
	string year_;
	string month_;
	string date_;
};

class Employee {
public:
	Employee(string employeeNum, string name, string cl, string phoneNum, string birthday, string certi);
	string getEmployeeNum();
	string getName();
	string getCl();
	string getPhoneNum();
	string getBirthday();
	string getCerti();
	string getFirstName();
	string getLastName();
	string getMiddlePhoneNum();
	string getLastPhoneNum();
	string getBirthdayYear();
	string getBirthdayMonth();
	string getBirthdayDate();
	void setName(string name);
	void setCl(string cl);
	void setPhoneNum(string phoneNum);
	void setBirthday(string birthday);
	void setCerti(string certi);
	bool operator<(const Employee& employee) {
		return this->employeeNum_ < employee.employeeNum_;
	}
	bool operator==(const Employee& employee) {
		return this->employeeNum_ == employee.employeeNum_;
	}

private:
	EmployeeNum employeeNum_;
	Name name_;
	string cl_;
	PhoneNumber phoneNum_;
	Date birthday_;
	string certi_;
};
