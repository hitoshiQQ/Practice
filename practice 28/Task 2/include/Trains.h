#pragma once
#include <string>
#include <chrono>
#include "Enter.h"
#include "Station.h"

class Station;

class Move {
protected:
	std::chrono::time_point<std::chrono::high_resolution_clock,
		std::chrono::duration<double, std::chrono::seconds::period>> start_t, arrival_t;
	std::chrono::duration<double, std::chrono::seconds::period> expected_t;

public:
	void start(std::chrono::high_resolution_clock::time_point start 
		= std::chrono::high_resolution_clock::now());
};

class Train : public Move {
public:
	int id;
	double speed;
	bool checkMoving;
	Station* station;

	Train(int id, Station* station, double time_station);
	void update();
	static void pace(Train* train);
	void printTime();
	void start(std::chrono::high_resolution_clock::time_point start
		= std::chrono::high_resolution_clock::now());
	void arrive(Station* station);
	void arrive_proccess();
};