#include <iostream>
#include "command.h"

using namespace std;

vector<string> loadInputFile(string path) {
	// TODO : 파일에서 라인당 string 하나씩 추출하여 commands_에 push_back 하는 코드 추가
	vector<string> commands;

	return commands;
}

void writeOutputFile(string path, vector<string> outputs) {
	// TODO : outputs_를 파일로 쓰는 코드 추가
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

