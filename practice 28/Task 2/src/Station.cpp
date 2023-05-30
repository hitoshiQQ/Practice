#include "Station.h"

class Station;
class Train;

Station* Station::station = new Station();

int Station::current_que = 0;
std::vector<Train*> Station::que;
std::mutex Station::access_queue;
std::mutex Station::access_line;

void Station::proccess() {
	Train* pTrain = nullptr;
	int trainCO = 0;
	while (trainCO < 3) {
		pTrain = deque();
		if (pTrain != nullptr) {
			access_line.lock();
			pTrain->arrive_proccess();
			pTrain = nullptr;
			trainCO++;
			access_line.unlock();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(30));
	}
}

void Station::arriving_proccess(Train* train) { 
	if (train == nullptr) {
		return;
	}
	enque(train);
}

void Station::enque(Train* train) {
	access_queue.lock();
	Enters::print("Train #" + std::to_string(train->id) + " wait in queue!\n");
	que.push_back(train);
	access_queue.unlock();
}

Train* Station::deque() {
	if (!que.empty() && current_que >= 0 && (que.size() - 1) >= current_que){
		access_queue.lock();
		Train* train = que.at(current_que++);
		Enters::print("Train #" + std::to_string(train->id) + " left que!\n");
		access_queue.unlock();
		return train;
	}else {
		return nullptr;
	}
}
