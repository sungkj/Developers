#pragma once

#include "pch.h"

#include "../Developers/command.cpp"
#include "../Developers/database.cpp"
#include "../Developers/employee.cpp"

TEST(DatabaseTest, SchTest) {
	DataBase* testList = new DataBase();
	// DB 추가 필요
	vector<Employee*> cmpList;
	Employee* employee = new Employee("1000", "LEE JY", "CL3", "010-1234-5678", "19001122", "PRO");

	cmpList.push_back(employee);
	testList->add(employee);

	EXPECT_EQ(testList->sch(' ', "employeeNum", "1000"), cmpList);

	EXPECT_EQ(testList->sch(' ', "name", "LEE JY"), cmpList);
	EXPECT_EQ(testList->sch('f', "name", "LEE"), cmpList);
	EXPECT_EQ(testList->sch('l', "name", "JY"), cmpList);

	EXPECT_EQ(testList->sch(' ', "cl", "CL3"), cmpList);

	EXPECT_EQ(testList->sch(' ', "phoneNum", "010-1234-5678"), cmpList);
	EXPECT_EQ(testList->sch('m', "phoneNum", "1234"), cmpList);
	EXPECT_EQ(testList->sch('l', "phoneNum", "5678"), cmpList);

	EXPECT_EQ(testList->sch(' ', "birthday", "19001122"), cmpList);
	EXPECT_EQ(testList->sch('y', "birthday", "1900"), cmpList);
	EXPECT_EQ(testList->sch('m', "birthday", "11"), cmpList);
	EXPECT_EQ(testList->sch('d', "birthday", "22"), cmpList);

	EXPECT_EQ(testList->sch(' ', "certi", "PRO"), cmpList);
}
