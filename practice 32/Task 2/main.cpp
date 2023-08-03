#include <iostream>
#include "nlohmann/json.hpp"
#include "data_process.h"
#include "find.h"


int main() {
	SaveFilmsBase();

	nlohmann::json data = DataRead();
	if (data == nullptr) {
		return -1;
	}

	for (int j = 0; j < data.size(); ++j) {
		std::cout << "\t# " << j + 1 << " || " << data[j]["Name"];
	}

	std::string cmd;
	do {
		std::cout << "\n\nEnter the movie title or actor's name or surname to find information!";
		cmd = getCommand();
		if (cmd.empty()) {
			continue;
		}
		std::cout << "Your request: " << cmd << std::endl;

		
		findMovie(cmd, data);
		findActor(cmd, data);
		
	} while (cmd != "exit");

	return 0;
}


