#include <iostream>
#include <vector>

void swapvec(std::vector<int>& const vec,int  arr[]) {
	for (int j = 0; j < vec.size(); ++j) {
		int temp = vec[j];
		vec[j] = arr[j];
		arr[j] = temp;
	}
}

void print(const std::vector<int>& const vec) {
	std::cout << "\nVector Print: ";
	for (const auto& el : vec) {
		std::cout << el << " ";
	}
}

void print(const int const arr[],const int& const size) {
	std::cout << "\nArray Print: ";
	for (int j = 0; j < size; ++j) {
		std::cout << arr[j] << " ";
	}
}

int main() {
	std::cout << "\t\tTask 1\n\n";

	std::vector<int> a{ 1,2,3,4 };
	int b[]{ 2,4,6,8 };
	int size_b = sizeof(b) / sizeof(int);
	
	print(a);
	print(b,size_b);

	swapvec(a, b);
	print(a);
	print(b, size_b);

	return 0;
}