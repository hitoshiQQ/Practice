#pragma once
#include <thread>
#include <vector>
#include <string>
#include "Swimmers.h"

class Threading {
public: 
	std::vector<std::thread> threads;
	void joinForAll();
};
