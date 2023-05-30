#pragma once
#include <chrono>
#include <thread>
#include <mutex>

class Timer {
private:
	static std::mutex access_t;

public:
	static std::chrono::time_point<std::chrono::high_resolution_clock,
		std::chrono::duration<double, std::chrono::seconds::period>> time_now();
};