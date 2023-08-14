#pragma once
#include <iostream>
#include "fishing.h"
#include "exception.h"

void game() {
	GameTable table [9] {};
	fieldCompletion(table);
	showTable(table);

	try {
		processGame(table);
	}catch (const FishFoundException& f) {
		std::cerr << f.what();
	}catch (const BootFoundException& b) {
		std::cerr << b.what();
	}
}
