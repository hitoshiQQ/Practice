#include "Swimmers.h"
#include "Result.h"
#include <string>

Swimmers::Swimmers(const int id, const double speed = 0) {
	this->id = id;
	this->speed = speed;
	distance = 0;
	past_t = std::chrono::seconds(0);
	checkSwimming = false;
}

void Swimmers::update() {
	if (checkSwimming) {
		std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
		past_t = std::chrono::duration<double, std::chrono::seconds::period>(now - start_t);
		distance = past_t.count() * speed;
	}
}

void Swimmers::pace(Swimmers* swimmer) {
	const int precision = 10;
	swimmer->start_t = std::chrono::high_resolution_clock::now();
	int co = 0, maxCO = 1000 / precision;
	if (1000 % precision) {
		++maxCO;
	}
	while (true) {
		swimmer->update();
		if (co < maxCO) {
			++co;
		}else {
			Enters::print("Swimmer #" + std::to_string(swimmer->id) 
				+ "|| Distance: " + std::to_string(swimmer->distance) + "\n");
			co = 0;
		}

		if (swimmer->distance >= 100) {
			swimmer->checkSwimming = false;
			swimmer->stop_t = std::chrono::high_resolution_clock::now();
			swimmer->past_t = std::chrono::duration<double>(swimmer->stop_t - swimmer->start_t);
			return;
		}
	}
}

void Swimmers::printTime() {
	Enters::print("Swimmer #" + std::to_string(id) + "|| Time: "
		+ std::to_string(past_t.count()) + "\n");
}

void Swimmers::start(std::chrono::high_resolution_clock::time_point start) {
	start_t = start;
	checkSwimming = true;
}