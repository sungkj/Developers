#include "employee_manager.h"
#include "command.h"

void EmployeeManager::readInput(Input* input) {
	commandStrs_ = input->load();

	if (commandStrs_.empty()) {
		cout << "ERROR : Input ���� �б� ����" << endl;
	}
}

void EmployeeManager::excute() {
	for (auto commandStr : commandStrs_) {
		Command* command = new Command(commandStr);
		command->execute();
		outputStrs_.push_back(command->getOutputText());
	}
}

void EmployeeManager::writeOutput(Output* output) {
	if (!output->save(outputStrs_)) {
		cout << "ERROR : Output ���� ���� ����" << endl;
	}
}
