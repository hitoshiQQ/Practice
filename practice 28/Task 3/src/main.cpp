#include <iostream>
#include "courier.h"
#include "threading.h"
#include "kitchen.h"
#include "onlineTrade.h"

int main() {
	Threading t;
	t.threads.emplace_back(Kitchen::kitchen_proccess);
	t.threads.emplace_back(OnlineShop::process);
	t.threads.emplace_back(Courier::process);
	t.joinForAll();

	return 0;
}