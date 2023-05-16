#include "Enter.h"
#include <iostream>

std::string getCommand() {
	std::string command;
	getline(std::cin, command);
	for (char& j : command) {
		j = (char)tolower(j);
	}
	return command;
}
