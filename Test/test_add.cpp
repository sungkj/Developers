#include "pch.h"

#include "test_header.h"

TEST(FunctionTest1, TestAdd) {
	DataBase* db = new DataBase();

	vector<Employee*> result;

	db->add(new Employee({ "14130827", "RPO JK", "CL4", "010-3231-1698", "20090201", "ADV" }));
	db->add(new Employee({ "15123099", "VXIHXOTH JHOP", "CL3", "010-3112-2609", "19771211", "ADV" }));
	db->add(new Employee({ "17112609", "FB NTAWR", "CL4", "010-5645-6122", "19861203", "PRO" }));

	result = db->sch(' ', "employeeNum", "14130827");
	EXPECT_EQ("14130827", result[0]->getEmployeeNum());

	result = db->sch(' ', "employeeNum", "15123099");
	EXPECT_EQ("15123099", result[0]->getEmployeeNum());

	result = db->sch(' ', "employeeNum", "17112609");
	EXPECT_EQ("17112609", result[0]->getEmployeeNum());
}
