#include "Source.h"
#include <vector>

void print(const std::vector<int>& const vec) {
	for (int j = 0; j < vec.size(); ++j) {
		std::cout << vec[j] << " ";
	}
}

void sort(std::vector<int>&const vec) {
	int step{ 0 };
	while (true) {
		if (vec[step] > 0) {
			break;
		}
		else {
			bool check_swap = false;
			for (int j = vec.size() - 1; j > step; --j) {
				if (abs(vec[step]) > abs(vec[j])) {
					int tmp = vec[step];
					for (int i = 0; i < j; ++i) {
						vec[i] = vec[i + 1];
					}
					vec[j] = tmp;
					check_swap = true;
					break;
				}
			}
			if (!check_swap) {
				++step;
			}
		}
	}
}


int main() {
	std::cout << "\t\tTask 4\n\n";

	std::vector<int> vec{-100,-50,-5,1,10,15};
	sort(vec);
	print(vec);

	return 0;
}