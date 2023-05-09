#include "gpu.h"

void gpuDisplay(std::vector<int> vec) {
	if (vec.size() != 8) {
		return;
	}
	for (int j = 0; j < vec.size(); ++j) {
		std::cout << vec.at(j) << std::endl;
	}
}
