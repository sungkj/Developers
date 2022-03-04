#include "pch.h"
#include "../Developers/input.cpp"
#include "../Developers/output.cpp"

TEST(InputTest, BasicTest) {
	Input input("input_20_20.txt");
	vector<string> commands = input.load();
	ASSERT_EQ(40, commands.size());
	EXPECT_EQ("ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV", commands[0]);
	EXPECT_EQ("ADD, , , ,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO", commands[1]);
	EXPECT_EQ("MOD,-p, , ,name,FB NTAWR,birthday,20050520", commands[21]);
	EXPECT_EQ("SCH, , , ,name,FB NTAWR", commands[39]);
}

TEST(OutputTest, BasicTest) {
	Output output("output_test.txt");
	vector<string> commands;
	commands.push_back("SCH,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV");
	commands.push_back("MOD,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO");
	commands.push_back("SCH,NONE");
	commands.push_back("DEL,1");
	commands.push_back("DEL,08117441,BMU MPOSXU,CL3,010-2703-3153,20010215,ADV");
	output.save(commands);

	ifstream ifs("output_test.txt");
	string str;
	vector<string> strs;
	while (getline(ifs, str)) {
		strs.push_back(str);
	}
	ASSERT_EQ(5, strs.size());
	EXPECT_EQ("SCH,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV", strs[0]);
	EXPECT_EQ("MOD,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO", strs[1]);
	EXPECT_EQ("SCH,NONE", strs[2]);
	EXPECT_EQ("DEL,1", strs[3]);
	EXPECT_EQ("DEL,08117441,BMU MPOSXU,CL3,010-2703-3153,20010215,ADV", strs[4]);
}