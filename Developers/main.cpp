#include <iostream>
#include "command.h"

using namespace std;

vector<string> loadInputFile(string path) {
	// TODO : ���Ͽ��� ���δ� string �ϳ��� �����Ͽ� commands_�� push_back �ϴ� �ڵ� �߰�
	vector<string> commands;

	return commands;
}

void writeOutputFile(string path, vector<string> outputs) {
	// TODO : outputs_�� ���Ϸ� ���� �ڵ� �߰�
}

int main(int argc, char* argv[]) {
	vector<string> commands;
	vector<string> outputs;

	commands = loadInputFile(argv[1]);
	for (auto command : commands) {
		Command* cmd = new Command(command);
		cmd->execute();
		outputs.push_back(cmd->getOutputText());
	}
	writeOutputFile(argv[2], outputs);

	return 0;
}

