#include <memory.h>

std::vector<float> memory_vector;

void memoryWrite(const std::vector<int> vec) {
	memory_vector.resize(vec.size());
	for (int j = 0; j < vec.size(); ++j) {
		memory_vector[j] = vec[j];
	}
}

std::vector<int> memoryRead() {
	std::vector<int> vec;
	vec.resize(memory_vector.size());
	for (int j = 0; j < memory_vector.size(); ++j) {
		vec[j] = memory_vector[j];
	}
	return vec;

}