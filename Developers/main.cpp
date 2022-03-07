#include <iostream>
#include "employee_manager.h"
#include "input.h"
#include "output.h"

using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "usage : " << argv[0] << " input.txt output.txt" << endl;
		return -1;
	}

	EmployeeManager manager;
	shared_ptr<Input> inputPtr = FactoryInput::createFileInput(argv[1]);
	shared_ptr<Output> outputPtr = FactoryOutput::createFileOutput(argv[2]);

	manager.execute(inputPtr, outputPtr);

	return 0;
}

