#include "pch.h"
#include "test_header.h"

TEST(FunctionTest1, TestDel) {
	DataBase* db = new DataBase();

	vector<Employee*> testList;
	vector<Employee*> result;

	testList.push_back(new Employee("15123099", "VXIHXOTH JHOP", "CL3", "010-3112-2609", "19771211", "ADV"));
	testList.push_back(new Employee("17112609", "FB NTAWR", "CL4", "010-5645-6122", "19861203", "PRO"));
	testList.push_back(new Employee("14130827", "RPO JK", "CL4", "010 - 3231 - 1698", "20090201", "ADV"));

	db->add(testList[0]);
	db->add(testList[1]);
	db->add(testList[2]);

	result.push_back(testList[1]);
	result.push_back(testList[2]);
	testList.pop_back();
	testList.pop_back();

	db->del(testList);

	vector<Employee*> dbList = db->getDBList();

	EXPECT_EQ(result, dbList);

}