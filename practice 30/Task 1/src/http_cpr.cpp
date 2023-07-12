#include "http_cpr.h"

void Requests::get() {
	cpr::Header header = _header;
	cpr::Url url = _url + "/get";
	cpr::Response res = cpr::Get(url, header);
	print(res);
}

void Requests::post() {
	cpr::Header header = _header;
	cpr::Url url = _url + "/post";
	cpr::Response res = cpr::Post(url, header);
	print(res);
}

void Requests::put() {
	cpr::Header header = _header;
	cpr::Url url = _url + "/put";
	cpr::Response res = cpr::Put(url, header);
	print(res);
}

void Requests::del() {
	cpr::Header header = _header;
	header.insert({ {"accept","application/json"} });
	cpr::Url url = _url + "/delete";
	cpr::Response res = cpr::Delete(url, header);
	print(res);
}

void Requests::patch()
{
	cpr::Header header = _header;
	cpr::Url url = _url + "/patch";
	cpr::Response res = cpr::Patch(url, header);
	print(res);
}

void Requests::print() {
	std::cout << responce.text << std::endl;
}