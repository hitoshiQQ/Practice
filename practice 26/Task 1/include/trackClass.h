#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

class Track {
	std::string name = "unkown";
	tm date;
	time_t time_duration;

public:
	void play() {
		std::cout << name << " || " << std::put_time(&date, "%d/%m/%Y") << " || " << time_duration << std::endl;
	}

	std::string getName() {
		return name;
	}
	tm getDate() {
		return date;
	}
	time_t getTimeDuration() {
		return time_duration;
	}

	static Track* tracking(std::string name, time_t date, time_t time_duration) {
		Track* track = new Track;
		track->name = name;
		track->date = *localtime(&date);
		track->time_duration = time_duration;
		return track;
	}
};