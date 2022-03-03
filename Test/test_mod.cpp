#include "pch.h"
#include "../Developers/command.cpp"
#include "../Developers/database.cpp"
#include "../Developers/employee.cpp"

TEST(FunctionTest1, TestMod) {
	DataBase* db = new DataBase();

	vector<Employee*> testList;

	testList.push_back(new Employee("15123099", "VXIHXOTH JHOP", "CL3", "010-3112-2609", "19771211", "ADV"));
	testList.push_back(new Employee("17112609", "FB NTAWR", "CL4", "010-5645-6122", "19861203", "PRO"));
	testList.push_back(new Employee("14130827", "RPO JK", "CL4", "010-3231-1698", "20090201", "ADV"));

	db->add(testList[0]);
	db->add(testList[1]);
	db->add(testList[2]);

	testList.pop_back();
	testList.pop_back();

	db->mod(testList, "name", "JOOHWAN KIM");

	vector<Employee*> dbList = db->getDBList();

	EXPECT_EQ(dbList[0]->getName(), "JOOHWAN KIM");
}