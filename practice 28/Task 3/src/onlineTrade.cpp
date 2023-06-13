#include "onlineTrade.h"

std::mutex OnlineShop::access;
std::vector<Order*>OnlineShop::orders;
std::string Order::type_str[] = { "UNKOWN","PIZZA","SOUP","STEAK","SALAD","SUSHI"};
std::string Order::phase_str[] = { "UNKOWN","CONFIRMED","COOKING","READY", "DELIVERY","DONE" };

std::string Order::toString(TYPE type) {
	if (type < 0 || type >= 6) {
		return type_str[0];
	}
	return type_str[type];
}

std::string Order::toString(PHASE phase) {
	if (phase < 0 || phase >= 6) {
		return phase_str[0];
	}
	return phase_str[phase];
}

Order::Order(TYPE type, PHASE phase =PHASE::UNKOWN) {
	this->setType(type);
	if (phase != PHASE::UNKOWN) {
		this->setPhase(phase);
	}else {
		this->setPhase(PHASE::CONFIRMED);
	}
}

Order::TYPE Order::getType() {
	return this->type;
}

void Order::setType(TYPE type) {
	if (type < 0 || type >= 6) {
		this->type = TYPE::NONE;
	}else {
		this->type = type;
	}
}

Order::PHASE Order::getPhase() {
	return phase;
}

void Order::setPhase(PHASE phase) {
	if (phase < 0 || phase >= 6) {
		phase = PHASE::UNKOWN;
	}
	this->phase = phase;
}

void Order::printOrder() {
	Enters::print("\n|ORDER| " + Order::toString(getType()) + " STATUS - " + Order::toString(getPhase()) + "\n");
}

Order* OnlineShop::getConfirmed() {
	Order* res = nullptr;
	for (int j = 0; j < orders.size(); ++j) {
		access.lock();
		if (!orders.empty() && orders.at(j)->getPhase() == Order::PHASE::CONFIRMED) {
			res = orders.at(j);
		}
		access.unlock();
	}
	return res;
}

void OnlineShop::order(Order::TYPE type) {
	access.lock();
	orders.emplace_back(new Order(type, Order::PHASE::CONFIRMED));
	access.unlock();
}

void OnlineShop::process() {
	for (int j = 0; j < 10; ++j) {
		Order::TYPE _type = (Order::TYPE)(rand() % 5 + 1);
		Enters::print("\n|SHOP| New order for " + Order::toString(_type) + "\n");
		OnlineShop::order(_type);
		if (j >= 9) {
			break;
		}
		std::this_thread::sleep_for(std::chrono::seconds(rand() % 5 + 10));
	}
	Enters::print("\n|SHOP| 10 order's!");
}

Order* OnlineShop::getPhase(Order::PHASE phase) {
	Order* res = nullptr;
	
	for (int j = 0; j < orders.size(); ++j) {
		access.lock();
		if (!orders.empty() && orders.at(j)->getPhase() == phase) {
			res = orders.at(j);
		}
		access.unlock();
	}
	return res;
}
