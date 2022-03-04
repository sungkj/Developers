#include "employee_manager.h"

void EmployeeManager::readInput(shared_ptr<Input> inputPtr) {
	commandStrs_ = inputPtr->load();

	if (commandStrs_.empty()) {
		cout << "ERROR : Failed to load input file" << endl;
	}
}

void EmployeeManager::execute() {
	DataBase db;
		
	for (auto commandStr : commandStrs_) {
		CmdManager* cmdManager = new CmdManager(&db);
		string outputStr = cmdManager->execute(commandStr);
		if (!outputStr.empty()) {
			outputStrs_.push_back(outputStr);
		}
	}
}

void EmployeeManager::writeOutput(Output* output) {
	if (!output->save(outputStrs_)) {
		cout << "ERROR : Failed to write output file" << endl;
	}
}
