#include "employee_manager.h"

void EmployeeManager::execute(shared_ptr<Input> inputPtr, shared_ptr<Output> outputPtr) {
	DataBase db;

	while (true) {
		string commandStr = inputPtr->read();
		if (commandStr.empty()) {
			break;
		}

		CmdManager* cmdManager = new CmdManager(&db);
		string outputStr = cmdManager->execute(commandStr);
		if (!outputStr.empty()) {
			if (!outputPtr->write(outputStr)) {
				cout << "ERROR : Write error" << endl;
				return;
			}
		}
	}
}
