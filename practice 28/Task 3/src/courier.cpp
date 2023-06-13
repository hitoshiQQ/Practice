#include "courier.h"

Courier* Courier::sample;

Courier::Courier() {
	timer = std::chrono::seconds(rand() % 10 + 5);
}

Courier* Courier::Sample() {
	if (sample == nullptr) {
		sample = new Courier;
	}
	return sample;
}

void Courier::process() {
	int co{ 0 };
	Order* curr;

	while (true) {
		curr = nullptr;
		if (co > 9) {
			break;
		}
		while (curr != nullptr) {
			curr->setPhase(Order::PHASE::DELIVERY);
			Enters::print("\n|COURIER| Order " + Order::toString(curr->getType()) + " is "
				+ Order::toString(curr->getPhase()) + "\n");
			std::this_thread::sleep_for(std::chrono::seconds(5 + rand() % 10));
			curr->setPhase(Order::PHASE::DONE);
			Enters::print("\n|COURIER| Order " + Order::toString(curr->getType()) + " is "
				+ Order::toString(curr->getPhase()) + "\n");
			co++;
		}
	}
	Enters::print("\n|COURIER| 10 orders delivered!");
}
