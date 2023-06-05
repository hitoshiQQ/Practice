#pragma once
#include "onlineTrade.h"
#include <mutex>

class Kitchen {
public:
	static Kitchen* sample;
	static std::mutex k_access;
	static void kitchen_proccess();
};