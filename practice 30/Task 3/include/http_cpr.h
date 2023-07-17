#pragma once
#include <iostream>
#include <string>
#include <map>
#include "cpr/cpr.h"

class Requests {
protected:
	cpr::Header _header;
	std::string name;
	cpr::Url _url;
	std::vector<cpr::Pair> parameters;
	cpr::Parameters* par;
	cpr::Payload* pay_load;
	cpr::Session* session;

	void print(cpr::Response response);
	void addParameters(std::string key, std::string val);
	void updatePar();
	void updatePayLoad();

public:
	~Requests();
	explicit Requests(std::string url);
	void get();
	void post();
	bool checkPar(std::string& key, std::string& val);
};