#include "Multithreading.h"

void TrainAccounting::joinForAll() {
	if (threads.size() <= 0) {
		return;
	}
	for (int j = 0; j < threads.size(); ++j) {
		if (threads[j].joinable()) {
			threads[j].join();
		}
	}
}