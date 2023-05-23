#pragma once
#include "Enter.h"
#include <chrono>

class Sportsman {
protected:
	std::chrono::high_resolution_clock::time_point start_t;
	std::chrono::high_resolution_clock::time_point stop_t;
	std::chrono::duration<double, std::chrono::seconds::period> past_t;

public:
	virtual void start(std::chrono::high_resolution_clock::time_point start) = 0;
};

class Swimmers : virtual public Sportsman {
public:
	int id;
	bool checkSwimming;
	double speed;
	double distance;
	Swimmers(int id, double speed);
	
	void update();
	static void pace(Swimmers* swimmer);
	void printTime();
	void start(std::chrono::high_resolution_clock::time_point start 
		= std::chrono::high_resolution_clock::now());
};