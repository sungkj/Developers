#pragma once

#include <iostream>
#include <string>

using namespace std;

struct EmployeeInfo {
	string employeeNum;
	string name;
	string cl;
	string phoneNum;
	string birthday;
	string certi;
};

class EmployeeNum {
public:
	EmployeeNum(const string employeeNum) {
		int employeeNumYear = stoul(employeeNum.substr(0, 2));
		if (employeeNumYear < minimumYear_) {
			employeeNum_ = stoi(employeeNum) + offset2000_;
		}
		else {
			employeeNum_ = stoi(employeeNum) + offset1900_;
		}
	}
	string get() const {
		return to_string(employeeNum_).substr(2);
	}
	bool operator<(const EmployeeNum& employeeNum) const {
		return this->employeeNum_ < employeeNum.employeeNum_;
	}
	bool operator==(const EmployeeNum& employeeNum) const {
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
	Name(const string name) {
		setName(name);
	}
	string getName() const {
		return firstName_ + " " + lastName_;
	}
	string getFirstName() const {
		return firstName_;
	}
	string getLastName() const {
		return lastName_;
	}
	void setName(const string name) {
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
	PhoneNumber(const string phoneNum) {
		setPhoneNum(phoneNum);
	}
	string getPhoneNum() const {
		return firstPhoneNum_ + "-" + middlePhoneNum_ + "-" + lastPhoneNum_;
	}
	string getMiddlePhoneNum() const {
		return middlePhoneNum_;
	}
	string getLastPhoneNum() const {
		return lastPhoneNum_;
	}
	void setPhoneNum(const string phoneNum) {
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
	Date(const string dateStr) {
		set(dateStr);
	}
	string get() const {
		return year_ + month_ + date_;
	}
	string getYear() const {
		return year_;
	}
	string getMonth() const {
		return month_;
	}
	string getDate() const {
		return date_;
	}
	void set(const string dateStr) {
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
	Employee(const EmployeeInfo employeeInfo);
	string getEmployeeNum() const;
	string getName() const;
	string getCl() const;
	string getPhoneNum() const;
	string getBirthday() const;
	string getCerti() const;
	string getFirstName() const;
	string getLastName() const;
	string getMiddlePhoneNum() const;
	string getLastPhoneNum() const;
	string getBirthdayYear() const;
	string getBirthdayMonth() const;
	string getBirthdayDate() const;
	string toString() const;
	void setName(const string name);
	void setCl(const string cl);
	void setPhoneNum(const string phoneNum);
	void setBirthday(const string birthday);
	void setCerti(const string certi);
	bool operator<(const Employee& employee) const {
		return this->employeeNum_ < employee.employeeNum_;
	}
	bool operator==(const Employee& employee) const {
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
