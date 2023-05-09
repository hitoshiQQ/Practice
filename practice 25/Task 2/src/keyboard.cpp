#include "keyboard.h"

std::vector<int> enterKeyBoard() {
	std::vector<int> new_vec;
	std::cout << "Enter 8 num's: ";
	std::string enter;
	std::stringstream stream;
	new_vec.resize(8);

	for (int j = 0; j < 8; ++j) {
		std::cout << j + 1 << " : ";
		std::cin >> enter;
		new_vec[j] = std::stoi(enter);
	}
	std::cout << "Enter stop!";
	return new_vec;
}