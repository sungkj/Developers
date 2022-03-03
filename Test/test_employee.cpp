#include "pch.h"
#include "../Developers/employee.cpp"

TEST(EmployeeTest, GetTest) {
	Employee employee("15123099", "VXIHXOTH JHOP", "CL3", "010-3112-2609", "19771211", "ADV");

	EXPECT_EQ("15123099", employee.getEmployeeNum());
	EXPECT_EQ("VXIHXOTH JHOP", employee.getName());
	EXPECT_EQ("CL3", employee.getCl());
	EXPECT_EQ("010-3112-2609", employee.getPhoneNum());
	EXPECT_EQ("19771211", employee.getBirthday());
	EXPECT_EQ("ADV", employee.getCerti());

	EXPECT_EQ("VXIHXOTH", employee.getFirstName());
	EXPECT_EQ("JHOP", employee.getLastName());
	EXPECT_EQ("3112", employee.getMiddlePhoneNum());
	EXPECT_EQ("2609", employee.getLastPhoneNum());
	EXPECT_EQ("1977", employee.getBirthdayYear());
	EXPECT_EQ("12", employee.getBirthdayMonth());
	EXPECT_EQ("11", employee.getBirthdayDate());
}

TEST(EmployeeTest, SetTest) {
	Employee employee("15123099", "VXIHXOTH JHOP", "CL3", "010-3112-2609", "19771211", "ADV");

	employee.setName("FB NTAWR");
	EXPECT_EQ("FB NTAWR", employee.getName());

	employee.setCl("CL4");
	EXPECT_EQ("CL4", employee.getCl());

	employee.setPhoneNum("010-1234-5678");
	EXPECT_EQ("010-1234-5678", employee.getPhoneNum());

	employee.setBirthday("19780101");
	EXPECT_EQ("19780101", employee.getBirthday());

	employee.setCerti("PRO");
	EXPECT_EQ("PRO", employee.getCerti());
}

