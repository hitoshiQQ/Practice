#include "Source.h"
#include <vector>

void shakersort(std::vector<int>&const vec) {

	bool flag_sort = true;
	int co{ 0 };
	while (flag_sort) {
		++co;
		int step = 0, start = 0, end = vec.size() - 1;

		for (int j = start; j < end; ++j) {
			if (vec[j] > vec[j + 1]) {
				std::swap(vec[j], vec[j + 1]);
				++step;
			}
		}
		--end;
		for (int j = end; j > 0; --j) {
			if (vec[j - 1] > vec[j]) {
				std::swap(vec[j], vec[j - 1]);
				++step;
			}
		}
		++start;
		if (step == 0) {
			flag_sort = false;
		}
	}
}

void process_insert(std::vector<int>&const vec) {
	int num;
	do {
		std::cout << "\nEnter number: ";
		std::cin >> num;
		if (num == -2) {
			break;
		}else if (num == -1) {
			shakersort(vec);
			if (vec.size() >= 5) {
				std::cout << "\nFifth number is: " << vec[4];
			}
			else {
				std::cerr << "\nThe size of your vector is less than 5";
			}
		}
		else {
			vec.push_back(num);
		}
	} while (num != -2);
}


int main() {
	std::cout << "\t\tTask 3\n\n";

	std::vector<int> vec;
	process_insert(vec);

	return 0;
}