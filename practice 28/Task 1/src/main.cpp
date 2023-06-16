#include <iostream>
#include <thread>
#include <mutex>
#include <cmath>
#include <ctime>
#include "Threading.h"
#include "Swimmers.h"

std::mutex access;

int main() {
	std::vector<Swimmers*> swimmers;
	Threading threading;

	for (int j = 1; j <= 6; ++j) {
		swimmers.push_back(new Swimmers(j, Enters::enterPositionDouble("Enter swimmer speed #" + std::to_string(j) + ": ")));
	}
	std::chrono::time_point<std::chrono::high_resolution_clock> start_t = std::chrono::high_resolution_clock::now();

	for (int j = 0; j < swimmers.size(); ++j) {
		threading.threads.emplace_back(Swimmers::pace, swimmers[j]);
		swimmers[j]->start(start_t);
	}

	threading.joinForAll();
	for (int j = 0; j < swimmers.size(); ++j) {
		swimmers[j]->printTime();
	}

	return 0;
}
