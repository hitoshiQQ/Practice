#include "Source.h"
#include <vector>

void print(std::vector<int> vec) {
	for (int j = 0; j < vec.size(); ++j) {
		std::cout << vec[j] << " ";
	}
}

int find_maxSum(std::vector<int>& vec, int& ind1, int& ind2) {
	int sum{ 0 };
	for (int j = ind1; j < vec.size() && j <= ind2; ++j) {
		sum += vec[j];
	}
	return sum;
}

void find_index(std::vector<int>& vec) {
	int ind1{ 0 };
	int ind2 = vec.size();
	int max = find_maxSum(vec, ind1, ind2);

	for (int j = 0; j < vec.size(); ++j) {
		for (int i = j; i < vec.size(); ++i) {
			int max_temp = find_maxSum(vec, j, i);
			if (max_temp > max) {
				max = max_temp;
				ind1 = j;
				ind2 = i;
			}
		}
	}
	std::cout << "\n\tIndex's: "<<ind1<<" | "<<ind2;
}

int main() {
	std::cout << "\t\tTask 1\n\n";

	std::vector<int> vec = { -2,1,-3,4,-1,2,1,-5,4 };
	find_index(vec);

	return 0;
}