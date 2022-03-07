#include "employee_manager.h"

void EmployeeManager::execute(shared_ptr<Input> inputPtr) {
	DataBase db;

	while (true) {
		string commandStr = inputPtr->read();
		if (commandStr.empty()) {
			break;
		}

		CmdManager* cmdManager = new CmdManager(&db);
		string outputStr = cmdManager->execute(commandStr);
		if (!outputStr.empty()) {
			outputStrs_.push_back(outputStr);
		}
	}
}

void EmployeeManager::writeOutput(shared_ptr<Output> outputPtr) {
	if (!outputPtr->save(outputStrs_)) {
		cout << "ERROR : Failed to write output file" << endl;
	}
}
