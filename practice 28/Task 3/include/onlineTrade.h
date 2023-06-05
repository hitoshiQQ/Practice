#pragma once

#include <vector>
#include <thread>
#include <mutex>
#include "kitchen.h"
#include "courier.h"
#include "Enter.h"

class Kitchen;
class Courier;

class Order {

public:
	enum TYPE {
		UNKOWN,
		PIZZA,
		SOUP,
		STEAK,
		SALAD,
		SUSHI,
	};

	enum PHASE {
		UNKOWN,
		CONFIRMED,
		COOKING,
		READY,
		DELIVERY,
		DONE,
	};

	std::mutex order_access;
	static string type_str[];
	static std::string phase_str[];
	static std::string toString(TYPE type);
	static std::string toString(PHASE phase);

	explicit Order(TYPE type, PHASE phase);
	TYPE getType();
	void setType(TYPE type);

	PHASE getPhase();
	void setPhase(Phase phase);
	
	void printOrder();

private:
	TYPE type;
	PHASE phase;
};

class OnlineShop {
public:
	static Order* getConfirmed();
	static std::mutex access;
	static std::vector<Order*> orders;
	static void order(Order::TYPE type);
	staitc void process();
	static Order* getPhase(Order::PHASE phase);
};
