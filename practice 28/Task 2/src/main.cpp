#include <iostream>
#include "Enter.h"
#include "Multithreading.h"
#include "Trains.h"

int main() {

	std::vector<Train*> trains;
	TrainAccounting check;

	for (int j = 1; j <= 3; ++j) {
		trains.push_back(new Train(j, Station::station, Enters::enterPositionDouble("Train #" + std::to_string(j) + "|\nEnter time to station: ")));
		check.threads.emplace_back(Train::pace, trains[j]);
	}
	check.threads.emplace_back(Station::proccess);
	for (int j = 0; j < trains.size(); ++j) {
		trains.at(j)->start();
	}

	check.joinForAll();


	return 0;
}