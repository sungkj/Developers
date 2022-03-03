#include "employee_manager.h"

void EmployeeManager::readInput(Input* input) {
	commandStrs_ = input->load();

	if (commandStrs_.empty()) {
		cout << "ERROR : Input ���� �б� ����" << endl;
	}
}

void EmployeeManager::execute() {
	DataBase db;
		
	for (auto commandStr : commandStrs_) {
		Command* command = new Command(&db);
		string outputStr = command->execute(commandStr);
		if (!outputStr.empty()) {
			outputStrs_.push_back(command->execute(commandStr));
		}
	}
}

void EmployeeManager::writeOutput(Output* output) {
	if (!output->save(outputStrs_)) {
		cout << "ERROR : Output ���� ���� ����" << endl;
	}
}
