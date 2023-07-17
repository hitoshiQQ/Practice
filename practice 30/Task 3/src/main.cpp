#include <iostream>
#include "http_cpr.h"


int main() {
	Requests r("http://httpbin.org");
	std::string commands[3] = { "get", "post","exit" };
	std::string cmd = "";
	int num_cmd;
	std::string key, val;

	while (true) {
		num_cmd = -1;
		key = val = "";

		std::cout << "Enter the new parameter key or command: \n";
		std::cin >> cmd;
		num_cmd = -1;
		for (int j = 0; j < 6; ++j) {
			if (cmd == commands[j]) {
				cmd = j;
				break;
			}
		}

		switch (cmd) {
		case 0: {
			r.get();
			break;
		}
		case 1: {
			r.post();
			break;
		}
		case 2: {
			return 0;
		}
		case -1:
		default: {
			key = cmd;
			std::cout << "Input Value:\n";
			std::cin >> val;
			cmd = "";
			if (r.checkPar(key, val)) {
				std::cout << "\nParameter  |ACCEPTED|:\n  key = |"" << key << "|", value = |"" << val << "|"" << std::endl;
			}
			else {
				std::cout << "\nParameter  |REJECTED|:\n  key = |"" << key << "|", value = |"" << val << "|"" << std::endl;
			}
			break;
		}
			
		}
	}
	return 0;
};