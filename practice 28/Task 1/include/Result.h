#pragma once
#include <thread>
#include <vector>
#include <string>
#include "Swimmers.h"

class Result {
public: 
	std::vector<std::thread> threads;
	void joinForAll();
};