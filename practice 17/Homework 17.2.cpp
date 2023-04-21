#include <iostream>

inline void swap(int& a, int& b) {
	a ^= b ^= a ^= b;
}

void reverse_array(int* arr, int size) {
	int mid = size / 2;
	for (int j = 0, i = (size - 1); j < mid; ++j, --i) {
		swap(*(arr + j),*(arr + i));
	}
}

void print_array(int* arr, int size) {
	for (int j = 0; j < size; ++j) {
		std::cout << *(arr + j) << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::cout << "\t\tTask 2\n\n";

	int arr[]{ 1,2,3,4,5,6,7,8,9,10 };
	int size = sizeof(arr) / sizeof(int);

	std::cout << "\nStarting array: ";
	print_array(arr, size);

	std::cout << "\nReversed array: ";
	reverse_array(arr, size);
	print_array(arr, size);

	return 0;
}