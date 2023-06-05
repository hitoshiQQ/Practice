#include "kitchen.h"
#include <thread>

std::mutex Kitchen::k_access;

Kitchen* Kitchen::sample = new Kitchen;

void Kitchen::kitchen_proccess() {
	int co = 0;
	Order* curr;

	while (true) {
		curr = nullptr;
		if (co >= 10) {
			break;
		}
		while (curr == nullptr) {
			curr = OnlineShop::getPhase(Order::PHASE::CONFIRMED);
		}
		if (curr != nullptr) {
			curr->setPhase(Order::PHASE::COOKING);
			Enters::print("\n|KITCHEN| Order " + Order::toString(curr->getType()) + " is "
				+ Order::toString(curr->getPhase()) + "\n");
			std::this_thread::sleep_for(std::chrono::seconds(5 + rand() % 10));
			curr->setPhase(Order::PHASE::READY);
			Enters::print("\n|KITCHEN| Order " + Order::toString(curr->getType()) + " is "
				+ Order::toString(curr->getPhase()) + "\n");

			co++;
		}	
	}
	Enters::print("\n|KITCHEN| 10 orders cooked!");
}