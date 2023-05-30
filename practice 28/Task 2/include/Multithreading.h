#pragma once
#include <thread>
#include <vector>

class TrainAccounting {
public:
	std::vector<std::thread> threads;
	void joinForAll();
};