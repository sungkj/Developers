#pragma once

#include <iostream>
#include <string>

using namespace std;

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
    unsigned int employeeNum_;
    string firstName_;
    string lastName_;
    string cl_;
    string middlePhoneNum_;
    string lastPhoneNum_;
    string birthdayYear_;
    string birthdayMonth_;
    string birthdayDate_;
    string certi_;
};
