#include <http_web_page.h>

void Requests::printHeader() {
	std::string tag1("<h1>");
	std::string tag2("</h1>");
	_header = { {"User-Agent","Mozilla/5.0 (Windows NT 10.0; Win64; x64) Chrome/114.0.5735.199 Safari/537.36"},
		{"accept", "text/html"} };
	url = cpr::Url("http://httpbin.org/html");
	cpr::Response res = cpr::Get(url, _header);
	auto start = res.text.find(tag1) + tag1.size();
	auto end = res.text.find(tag2, start);
	std::cout << res.text.substr(start, end - start);
}

