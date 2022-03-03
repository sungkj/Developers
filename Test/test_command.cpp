#include "pch.h"
#include "../Developers/command.cpp"
#include "../Developers/database.cpp"
#include "../Developers/employee.cpp"

TEST(CommandTest, Positive) {

	DataBase testDB;
	Command* cmd = new Command(&testDB);

	cmd->execute("ADD, , , ,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO");
	cmd->execute("ADD, , , ,18115040,TTETHU HBO,CL3,010-4581-2050,20080718,ADV");

	string expected_results[] = {
	"MOD,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO",
	"DEL,1",
	"MOD,17112609,FB NTAWR,CL4,010-5645-6122,20050520,PRO",
	"SCH,1",
	"NONE"
	};

	EXPECT_EQ(cmd->execute("MOD,-p, , ,name,FB NTAWR,birthday,20050520"), expected_results[0]);
	EXPECT_EQ(cmd->execute("DEL, , , ,employeeNum,18115040"), expected_results[1]);
	EXPECT_EQ(cmd->execute("MOD,-p, , ,name,FB NTAWR,cl,CL3"), expected_results[2]);
	EXPECT_EQ(cmd->execute("SCH, , , ,name,FB NTAWR"), expected_results[3]);
	EXPECT_EQ(cmd->execute("SCH, ,-d, ,birthday,04"), expected_results[4]);

}