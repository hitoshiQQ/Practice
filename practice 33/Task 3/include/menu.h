#pragma once
#include <iostream>
#include "additional_elements.h"
#include "data_registry.h"


void menu() {
	DataRegistry<int, std::string> data;
	std::string cmd;
	showCommand();

	do {
		std::cin.clear();
		fflush(stdin);

		std::cout << "\nEnter your opinion: ";
		cmd = getCommand();

		if (cmd == "add") {
			data.add();
		}else if (cmd == "find") {
			data.find();
		}else if (cmd == "list") {
			data.list();
		}else if (cmd == "remove") {
			data.remove();
		}

	} while (cmd != "exit");
}



