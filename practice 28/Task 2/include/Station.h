#pragma once
#include <mutex>
#include <vector>
#include <thread>
#include "Trains.h"

class Train;

class Station {
public:
	static Station* station;
	static int current_que;
	static std::vector<Train*> que;
	static std::mutex access_queue;
	static std::mutex access_line;

	static void proccess();
	static void arriving_proccess(Train* train = nullptr);
	static void enque(Train*);
	static Train* deque();

	~Station() {
		delete station;
	}
};