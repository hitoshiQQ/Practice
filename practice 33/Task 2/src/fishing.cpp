#include <iostream>
#include <random>
#include "fishing.h"
#include "exception.h"


void field—ompletion(GameTable* table) {
	std::random_device rand;
	std::mt19937 gen(rand());
	std::uniform_int_distribution<> dist(0, 9 - 1);

	table[dist(gen)].fish = true;
	for (int j = 0; j < 3;) {
		int i = dist(gen);
		if (!table[i].fish && !table[i].boot) {
			table[i].boot = true;
			++j;
		}
	}
}

void processGame(GameTable* table) {
	do {
		int num;
		std::cout << "\nEnter the sector number: ";
		std::cin >> num;
		if (num < 0 || num > 9 - 1) {
			std::cout << "\nIncorrect input.Try again!";
			continue;
		}else if (table[num].fish) {
			throw FishFoundException();
		}else if (table[num].boot) {
			throw BootFoundException();
		}
		std::cout << "\nYou couldn't catch anything!";

	} while (true);
}

void showTable(GameTable* table) {
	
	std::cout << "\n Game Table |";
	for (int j = 0; j < 9; ++j) {
		char c = '.';
		if (table[j].fish) {
			c = 'f';
		}else if (table[j].boot) {
			c = 'b';
		}
		std::cout << c;
	}
	std::cout << "|\n";
	std::cout << "===========================\n\n";
}