#include "Source.h"
#include <vector>


void create_world(bool world[][5][10]) {
	int height[5][5]; int num;

	std::cout << "\nEnter height: ";
	for (int j = 0; j < 5; ++j) {
		for (int i = 0; i < 5; ++i) {
			std::cin >> num;
			if (num < 0 || num>10) {
				do {
					std::cout << "\nIncorrect number!Try again!";
					std::cin >> num;
				} while (num < 0 || num>10);
			}
			height[j][i] = num;
		}
	}

	for (int j = 0; j < 5; ++j) {
		for (int i = 0; i < 5; ++i) {
			for (int q = 0; q < height[j][i]; ++q) {
				world[j][i][q] = true;
			}
			for (int q = height[j][i]; q < 10; ++q) {
				world[j][i][q] = false;
			}
		}
	}
}

void slice_world(bool world[][5][10], int& num) {
	for (int j = 0; j < 5; ++j) {
		for (int i = 0; i < 5; ++i) {
			std::cout << world[j][i][num - 1] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;
}

bool check_num(int& num) {
	if (num < 1 || num>10) {
		return false;
	}
	return true;
}

int main() {

	std::cout << "\t\tMaincraft\n\n";

	bool world[5][5][10];
	

	create_world(world);

	int slice_line;
	while (true) {
		std::cout << "Enter slice line number: ";
		std::cin >> slice_line;

		if (!check_num(slice_line)) {
			std::cout << "\n\n\tIncorrcet!Try again!";
			std::cin >> slice_line;
			continue;
		}

		slice_world(world, slice_line);
	}

	return 0;
}