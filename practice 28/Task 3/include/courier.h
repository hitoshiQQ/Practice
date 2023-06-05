#pragma once

#include <chrono>
#include <random>

#include "onlineTrade.h"

class Courier {
private:
	std::chrono::duration<double> timer;

public:
	static Courier* sample;
	Courier* Sample();
	Courier();
	static void process();
};