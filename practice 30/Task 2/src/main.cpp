#include <iostream>
#include "http_web_page.h"


int main() {
	Requests r("httpbin.org");
	r.printHeader();

	return 0;
};