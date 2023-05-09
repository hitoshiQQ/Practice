#include "operation_process.h"

void enterOperation(std::vector <MyCommand>& cmd) {
	MyCommand new_cmd;
	do {
		fillCommand(new_cmd);
		if (cmd.empty() && new_cmd._command != SCALPEL) {
			std::cout << "\n\t\tThe first command must be SCALPEL!\n";
			continue;
		}
		else if (new_cmd._command == FINISH && cmd.back()._command != SUTURE) {
			std::cout << "\n\t\tOperation cannot be finished: -" << command_str[cmd.back()._command] << std::endl;
		}
		else if (new_cmd._command == SUTURE && checkLine(cmd.front().coords, cmd.back().coords)) {
			cmd.push_back(new_cmd);
			std::cout << "Operation finished!\n";
			break;
		}
		else if (new_cmd._command == TWEEZERS || new_cmd._command == HEMOSTAT) {
			if (checkPointLine(cmd.front().coords[0], cmd.front().coords[1], new_cmd.coords[0])){
				std::cout << "\n Point on operation line!!!\n";
			}else {
				std::cout << "\n Point off operation line!\n";
				cmd.push_back(new_cmd);
			}
		}
		else if (new_cmd._command != NONE && new_cmd._command != FINISH) {
			cmd.push_back(new_cmd);
		}
	} while (new_cmd._command != FINISH);
}

bool checkOperation(std::vector <MyCommand>& op) {
	MyCommand start_op = op.front();
	MyCommand end_op = op.back();

	if (start_op._command == SCALPEL && end_op._command == SUTURE \
		&& checkLine(start_op.coords, end_op.coords)) {
		return true;
	}
	return false;
}

void processOperation(std::vector <MyCommand>& op) {
	for (std::vector<MyCommand>::iterator iter = op.begin(); iter != op.end(); ++iter) {
		processCommand(*iter);
	}
}