#include "hdd.h"

std::vector<int> hddLoad() {
	std::vector<int> vec;
	vec.resize(8);
	for (int j = 0; j < 8; ++j) {
		vec[j] = 0;
	}

	std::ifstream file("F:\\C++\\Computer\\data\\data.txt");
	if (!file.is_open()) {
		return vec;
	}
	for (int j = 0; !file.eof() && j < vec.size(); ++j) {
		file >> vec[j];
	}
	return vec;
}

bool hddSave(std::vector<int> vec) {
	if (vec.size() != 8) {
		return false;
	}
	std::ofstream file("F:\\C++\\Computer\\data\\data.txt");
	if (!file.is_open()) {
		return false;
	}
	if (vec.size() == 8) {
		for (int j = 0; j < vec.size(); ++j) {
			file << vec[j] << " ";
		}
		return true;
	}else {
		return false;
	}
}
