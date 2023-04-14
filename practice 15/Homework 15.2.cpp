#include "Source.h"
#include <vector>

void find_pair(const std::vector<int>& const vec,const int& res)  {
	for (int j = 0; j < vec.size(); ++j) {
		for (int i = j; i < vec.size(); ++i) {
			if (vec[j] + vec[i] == res) {
				std::cout << "\nResult: " << vec[j] << " | " << vec[i];
				return;
			}
		}
	}
}

int main() {
	std::cout << "\t\tTask 2\n\n";

	std::vector<int> vec{ 2,7,11,15 };
	int res{ 9 };

	find_pair(vec, res);

	return 0;
}