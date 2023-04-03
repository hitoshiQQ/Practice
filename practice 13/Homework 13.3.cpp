#include "Source.h"
#include <vector>
#include <cassert>

int main() {

	cout << "\t\tTask 3\n\n";

	std::vector<int> vec(20);

	while (true) {
		int add_num;
		std::cout << "Enter the number: ";
		std::cin >> add_num;
		if (add_num == -1) {
			for (int j = 0; j < vec.size(); ++j) {
				std::cout << vec[j] << " \n";
			}
		}else if(vec.size()==20){
			vec.erase(vec.begin());
			vec.push_back(add_num);
		}else {
			vec.push_back(add_num);
		}
	}

	return 0;
}