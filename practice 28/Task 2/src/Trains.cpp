#include <string>
#include "Trains.h"
#include "Multithreading.h"
#include "Timer.h"


void Move::start(std::chrono::high_resolution_clock::time_point start) {}

Train::Train(const int id, Station* station, const double time_station = 0.1) {
	this->id = id;
	this->station = station;
	expected_t = std::chrono::duration<double, std::chrono::seconds::period>(time_station);
	checkMoving = false;
}

void Train::update() {
	if (checkMoving) {
		std::chrono::time_point<std::chrono::high_resolution_clock
			,std::chrono::duration<double>> now = Timer::time_now();
	}
}

void Train::pace(Train* train) {
	train->start_t = Timer::time_now();
	train->arrival_t = std::chrono::time_point<std::chrono::high_resolution_clock,
		std::chrono::duration<double>>(train->start_t + train->expected_t);

	while (true) {
		train->update();
		if (std::chrono::duration<double>(train->arrival_t - Timer::time_now()).count() < 0) {
			train->checkMoving = false;
			train->arrival_t = Timer::time_now();
			train->expected_t = std::chrono::duration<double>(train->arrival_t - train->start_t);
			train->arrive(train->station);
			return;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
}

void Train::printTime() {
	Enters::print("Train #" + std::to_string(id) +
		" || Time: " + std::to_string(expected_t.count()) + "\n");
} 

void Train::start(std::chrono::high_resolution_clock::time_point start) {
	start_t = start;
	arrival_t = std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::duration<double>>(start_t + expected_t);
	checkMoving = true;
}

void Train::arrive(Station* station) {
	station->enque(this);
}

void Train::arrive_proccess() {
	Enters::print("Train #" + std::to_string(id) + "ARRIVED!\n");
	while (Enters::enterStr("\nEnter [depart] for train's departure: ") != "depart") {
		Enters::print("Train #" + std::to_string(id) + " Incorrect input.Tru again!\n");
	}
	Enters::print("Train #" + std::to_string(id) + " departed!\n");
}