#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "cpr/cpr.h"

class Requests {
protected:
	const static std::string ur;
	cpr::Header _header;
	cpr::Url url;

public:
	explicit Requests(std::string _url) { url = cpr::Url(_url); }
	void printHeader();
};