#include "cpu.h"

int cpuComputer(std::vector<int> vec) {
	int sum = 0;
	for (int j = 0; j < vec.size(); ++j) {
		sum += vec.at(j);
	}
	std::cout << sum << std::endl;
	return sum;
}