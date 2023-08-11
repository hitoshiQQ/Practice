#pragma once
#include <iostream>
#include "fishing.h"
#include "exception.h"

void game() {
	GameTable table [9] {};
	field—ompletion(table);
	showTable(table);

	try {
		processGame(table);
	}catch (const FishFoundException& f) {
		std::cerr << f.what();
	}catch (const BootFoundException& b) {
		std::cerr << b.what();
	}
}
