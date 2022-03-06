#include "pch.h"
#include "test_header.h"

TEST(FunctionTest1, TestDel) {
	DataBase* db = new DataBase();

	vector<Employee*> delList;
	vector<Employee*> result;

	db->add(new Employee("14130827", "RPO JK", "CL4", "010-3231-1698", "20090201", "ADV"));
	db->add(new Employee("15123099", "VXIHXOTH JHOP", "CL3", "010-3112-2609", "19771211", "ADV"));
	db->add(new Employee("17112609", "FB NTAWR", "CL4", "010-5645-6122", "19861203", "PRO"));

	delList.push_back(new Employee("14130827", "RPO JK", "CL4", "010-3231-1698", "20090201", "ADV"));
	delList.push_back(new Employee("15123099", "VXIHXOTH JHOP", "CL3", "010-3112-2609", "19771211", "ADV"));

	db->del(delList);

	result = db->sch(' ', "certi", "PRO");

	EXPECT_EQ("17112609", result[0]->getEmployeeNum());
}