#include "surgical_tools.h"
#include <iostream>

void scalpel(std::vector<Coordinate>& c) {
	if (c.size() != 2) {
		return;
	}
	std::cout << "\nScalpel cut: ";
	printCoordinate(c.front());
	std::cout << " : ";
	printCoordinate(c.at(1));
	std::cout << std::endl;
}

void hemostat(std::vector<Coordinate>& c) {
	if (c.size() != 1) {
		return;
	}
	std::cout << "\nHemostat on: ";
	printCoordinate(c.front());
	std::cout << std::endl;
}

void tweezers(std::vector<Coordinate>& c) {
	if (c.size() != 1) {
		return;
	}
	std::cout << "Tweezers on: ";
	printCoordinate(c.front());
	std::cout << std::endl;
}

void suture(std::vector<Coordinate>& c) {
	if (c.size() != 2) {
		return;
	}
	std::cout << "\nSuture: ";
	printCoordinate(c.front());
	std::cout << " : ";
	printCoordinate(c.at(1));
	std::cout << std::endl;
}

enum Command enterCommand() {
	std::cout << "\n\nAvailable commands: ";
	for (int j = 0; j < command_str.size(); ++j) {
		std::cout << command_str[j] << " ";
	}
	std::cout << std::endl;

	std::string command_enter = enterString("Enter command: ");
	
	Command cmd_out = NONE;

	if (command_enter == command_str[SCALPEL]) {
		cmd_out = SCALPEL;
	}else if (command_enter == command_str[HEMOSTAT]) {
		cmd_out = HEMOSTAT;
	}else if (command_enter == command_str[TWEEZERS]) {
		cmd_out = TWEEZERS;
	}else if (command_enter == command_str[SUTURE]) {
		cmd_out = SUTURE;
	}else if (command_enter == command_str[FINISH]) {
		cmd_out = FINISH;
	}
	return cmd_out;
}


void fillCommand(MyCommand& my_cmd) {
	do {
		my_cmd._command = enterCommand();
	} while (my_cmd._command == NONE);

	switch (my_cmd._command) {
	    case SCALPEL:
		case SUTURE: {
			enterCommandCoordinate(my_cmd.coords, 2);
			break;
		}
		case HEMOSTAT:
		case TWEEZERS: {
			enterCommandCoordinate(my_cmd.coords, 1);
			break;
		}
		case FINISH:
			break;
		case NONE:

		default:
			break;
	}
}

void enterCommandCoordinate(std::vector<Coordinate>& crd, int amount) {
	crd.clear();
	if (amount == 1) {
		crd.push_back(enterCoordinate("\nPoint: "));	
	}else if (amount == 2) {
		crd.push_back(enterCoordinate("\nBegin: "));
		crd.push_back(enterCoordinate("\nEnd: "));
	}
}

void processCommand(MyCommand& my_cmd) {
	switch (my_cmd._command) {
	   case SCALPEL: {
		   scalpel(my_cmd.coords);
		   break;
	   }
	   case HEMOSTAT: {
		   hemostat(my_cmd.coords);
		   break;
	   }
	   case TWEEZERS: {
		   tweezers(my_cmd.coords);
		   break;
	   }
	   case SUTURE: {
		   suture(my_cmd.coords);
		   break;
	   }
	   case NONE:
	   default:
		   break;
	}
}