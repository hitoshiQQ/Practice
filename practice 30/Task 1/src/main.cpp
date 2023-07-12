#include <iostream>
#include "http_cpr.h"

int main() {
	Requests r("http://httpbin.org");

	std::string cmd[6] = { "get", "post", "put", "delete", "patch","exit" };
	std::string _cmd = "unkown";
	int num_cmd;

	while (true) {
		num_cmd = -1;
		while (cmd < 0) {
			std::cout << "\nEnter command: ";
			std::cin >> _cmd;
			cmd = -1;
			for (int j = 0; j < 6; ++j) {
				if (_cmd == cmd[j]) {
					num_cmd = j;
					break;
				}
			}
		}
		switch (num_cmd) {
		   case 0: {
			   r.get();
			   break;
		   }
		   case 1: {
			   r.post();
			   break;
		   }
		   case 2: {
			   r.put();
			   break;
		   }
		   case 3: {
			   r.del();
			   break;
		   }
		   case 4: {
			   r.patch();
			   break;
		   }
		   case 5: {
			   return 0;
		   }

		   default: {
			   _cmd = "unkown";
			   break;
		   }
		}
	}
	return 0;
}
