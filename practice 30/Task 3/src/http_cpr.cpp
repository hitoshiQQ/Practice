#include "http_cpr.h"

Requests::Requests(std::string url) {
	_url = cpr::Url(url);
	_header = cpr::Header = ({ {"User-Agent","Mozilla/5.0 (Windows NT 10.0; Win64; x64) Chrome/114.0.5735.199 Safari/537.36"},
		                      {"Accept", "text/html"} });
	parameters.clear();
	par = nullptr;
	pay_load = nullptr;
	session.SetHeader(_header);
}

Requests::~Requests() {
	delete par;
	delete pay_load;
}

void Requests::print(cpr::Response response) {
	std::cout < responce.text << "\n";
}

void Requests::addParameters(std::string key, std::string val) {
	parameters.push_back(cpr::Pair(key, val));
}

void Requests::updatePar() {
	delete par;

	par = nullptr;
	par = new cpr::Parameters;
	for (auto iter = parameters.begin(); iter != parameters.end(); ++iter) {
		std::string k = iter._Ptr->key;
		std::string v = iter._Ptr->value;
		par->Add({ k,v });
	}
	parameters.clear();
}

void Requests::updatePayLoad() {
	delete pay_load;
	pay_load = nullptr;
	pay_load = new cpr::Payload(parameters.begin(), parameters.end());
	parameters.clear();
}

void Requests::get() {
	updatePar();
	cpr::Url url = _url + "/get";
	session.SetUrl(url);
	session.SetParameters(*par);
	cpr::Response result = session.Get();
	print(result);
}

void  Requests::post() {
	updatePayLoad();
	cpr::Url url = _url + "/post";
	session.SetUrl(url);
	session.SetPayload(*pay_load);
	cpr::Response result = session.Post();
	print(result);
}

bool Requests::checkPar(std::string& key, std::string& val) {
	if (key.size() <= 0 || val.size() <= 0) {
		return false;
	}
	std::pair<std::string, std::string> pair(key, val);
	addParameters(pair.first, pair.second);
	return true;
}