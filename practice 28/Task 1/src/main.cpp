#include <iostream>
#include <thread>
#include <mutex>
#include <cmath>
#include <ctime>
#include "Result.h"
#include "Swimmers.h"

std::mutex access;

int main() {
	std::vector<Swimmers*> swimmers;
	Result result;

	for (int j = 1; j <= 6; ++j) {
		swimmers.push_back(new Swimmers(j, Enters::enterPositionDouble("Enter swimmer speed #" + std::to_string(j) + ": ")));
	}
	std::chrono::time_point<std::chrono::high_resolution_clock> start_t = std::chrono::high_resolution_clock::now();

	for (int j = 0; j < swimmers.size(); ++j) {
		result.threads.emplace_back(Swimmers::pace, swimmers[j]);
		swimmers[j]->start(start_t);
	}

	result.joinForAll();
	for (int j = 0; j < swimmers.size(); ++j) {
		swimmers[j]->printTime();
	}

	return 0;
}