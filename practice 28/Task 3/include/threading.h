#pragma once
#include <thread>
#include <vector>

class Threading {
public:
	std::vector<std::thread> threads;
	void joinForAll();
};