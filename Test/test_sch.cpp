
#pragma once

#include "pch.h"

#include "../Developers/command.cpp"
#include "../Developers/database.cpp"
#include "../Developers/employee.cpp"

TEST(DatabaseTest, SchTest) {
	DataBase* testList = new DataBase();
	
	vector<Employee*> cmpList;
	Employee* employee = new Employee("1000", "LEE JY", "CL3", "010-1234-5678", "19001122", "PRO");

	cmpList.push_back(employee);
	testList->add(employee);

	EXPECT_EQ(testList->sch("employeeNum", ' ', "1000"), cmpList);

	EXPECT_EQ(testList->sch("name", ' ', "LEE JY"), cmpList);
	EXPECT_EQ(testList->sch("name", 'f', "LEE"), cmpList);
	EXPECT_EQ(testList->sch("name", 'l', "JY"), cmpList);

	EXPECT_EQ(testList->sch("cl", 'd', "CL3"), cmpList);

	EXPECT_EQ(testList->sch("phoneNum", ' ', "010-1234-5678"), cmpList);
	EXPECT_EQ(testList->sch("phoneNum", 'm', "1234"), cmpList);
	EXPECT_EQ(testList->sch("phoneNum", 'l', "5678"), cmpList);

	EXPECT_EQ(testList->sch("birthday_year", ' ', "19001122"), cmpList);
	EXPECT_EQ(testList->sch("birthday_year", 'y', "1900"), cmpList);
	EXPECT_EQ(testList->sch("birthday_year", 'm', "11"), cmpList);
	EXPECT_EQ(testList->sch("birthday_year", 'd', "22"), cmpList);

	EXPECT_EQ(testList->sch("certi", ' ', "PRO"), cmpList);
}