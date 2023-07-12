#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "cpr/cpr.h"

class Requests {
protected:
	cpr::Header _header = cpr::Header({ {"User-Agent","Mozilla/5.0 (Windows NT 10.0; Win64; x64) Chrome/114.0.5735.199 Safari/537.36"} });
	std::string name;
	cpr::Url _url = cpr::Url("http://httpbin.org");
	void print(cpr::Response r);
public:
	explicit Requests(std::string c_url) { _url = cpr::Url(c_url); }
	void get();
	void post();
	void put();
	void del();
	void patch(); 
	void patch(); 
};


