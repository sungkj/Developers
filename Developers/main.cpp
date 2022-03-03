#include <iostream>
#include "employee_manager.h"
#include "input.h"
#include "output.h"

using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "���ڰ� 2�� �ʿ��մϴ�." << endl;
		cout << "usage : " << argv[0] << " input.txt output.txt" << endl;
		return -1;
	}

	EmployeeManager manager;
	Input input(argv[1]);
	Output output(argv[2]);

	manager.readInput(&input);
	manager.excute();
	manager.writeOutput(&output);

	return 0;
}

