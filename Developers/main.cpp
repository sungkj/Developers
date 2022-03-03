#include <iostream>
#include "input.h"
#include "output.h"
#include "command.h"

using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "���ڰ� 2�� �ʿ��մϴ�." << endl;
		cout << "usage : " << argv[0] << " input.txt output.txt" << endl;
		return -1;
	}

	vector<string> outputs;
	Input input(argv[1]);
	Output output(argv[2]);

	vector<string> commands = input.load();
	if (commands.empty()) {
		cout << "ERROR : Input ���� �б� ����" << endl;
	}

	for (auto command : commands) {
		Command* cmd = new Command(command);
		cmd->execute();
		outputs.push_back(cmd->getOutputText());
	}

	if (!output.save(outputs)) {
		cout << "ERROR : Output ���� ���� ����" << endl;
	}

	return 0;
}

