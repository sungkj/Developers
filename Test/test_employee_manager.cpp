#include "pch.h"
#include "../Developers/input.cpp"
#include "../Developers/output.cpp"
#include "../Developers/command.cpp"
#include "../Developers/cmd_parser.cpp"
#include "../Developers/employee.cpp"
#include "../Developers/database.cpp"
#include "../Developers/employee_manager.cpp"

TEST(EmployeeManagerTest, BasicTest) {
    EmployeeManager manager;
    shared_ptr<Input> input = FactoryInput::createFileInput("input_20_20.txt");
    shared_ptr<Output> output = FactoryOutput::createFileOutput("output_test.txt");

    manager.readInput(input);
    manager.execute();
    manager.writeOutput(output);

    string expectedResults[] = {"SCH,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV",
        "MOD,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO",
        "SCH,NONE",
        "DEL,1",
        "DEL,08117441,BMU MPOSXU,CL3,010-2703-3153,20010215,ADV",
        "SCH,88114052,NQ LVARW,CL4,010-4528-3059,19911021,PRO",
        "SCH,01122329,DN WD,CL4,010-7174-5680,20071117,PRO",
        "SCH,03113260,HH LTUPF,CL2,010-5798-5383,19791018,PRO",
        "SCH,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO",
        "SCH,08123556,WN XV,CL1,010-7986-5047,20100614,PRO",
        "SCH,6",
        "SCH,88114052,NQ LVARW,CL4,010-4528-3059,19911021,PRO",
        "SCH,01122329,DN WD,CL4,010-7174-5680,20071117,PRO",
        "SCH,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV",
        "SCH,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO",
        "SCH,08108827,RTAH VNUP,CL4,010-9031-2726,19780417,ADV",
        "SCH,1",
        "MOD,17112609,FB NTAWR,CL4,010-5645-6122,20050520,PRO",
        "MOD,08123556,WN XV,CL1,010-7986-5047,20100614,PRO",
        "SCH,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO",
        "SCH,18117906,TWU QSOLT,CL4,010-6672-7186,20030413,PRO",
        "SCH,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO",
        "SCH,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV",
        "SCH,NONE",
        "SCH,10127115,KBU MHU,CL3,010-3284-4054,19660814,ADV",
        "MOD,85125741,FBAH RTIJ,CL1,010-8900-1478,19780228,ADV",
        "SCH,NONE",
        "MOD,1",
        "SCH,1"};
    ifstream ifs("output_test.txt");
    string str;
    vector<string> strs;
    while (getline(ifs, str)) {
        strs.push_back(str);
    }

    ASSERT_EQ(29, strs.size());
    for (int i = 0; i < 29; i++) {
        EXPECT_EQ(expectedResults[i], strs[i]);
    }
}
