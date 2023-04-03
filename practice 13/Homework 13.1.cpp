#include "Source.h"
#include <vector>
#include <cassert>

void delete_nums(std::vector<int>& vec, int& del) {
	for (int j = 0; j < vec.size() - 1; ++j) {
		if (vec[j] == del) {
			for (int i = j; i < vec.size() - 1; ++i) {
				std::swap(vec[i], vec[i + 1]);
			}
			vec.pop_back();
			--j;
		}
	}
}

void print(std::vector<int>& vec) {
	for (int j = 0; j < vec.size(); ++j) {
		std::cout << vec[j] << " ";
	}
}

int main() {

	std::cout << "\t\tTask 1\n\n";

	int size;
	std::cout << "Enter the size: ";
	std::cin >> size;
	assert(size >= 1);

	std::vector<int> num(size);
	std::cout << "Enter the numbers: ";
	for (int j = 0; j < num.size(); ++j) {
		std::cin >> num[j];
	}

	int delete_num;
	std::cout << "Enter the number to delete: ";
	std::cin >> delete_num;
	assert(delete_num <= size);

	delete_nums(num, delete_num);
	std::cout << "Result: ";
	print(num);

	return 0;
}