#include <iostream>

inline void swap(int* a, int* b) {
	*a ^= *b ^= *a ^= *b;
}

int main() {
	std::cout << "\t\tTask 1\n\n";
	int a{ 10 }, b{ 20 };

	swap(&a, &b);

	std::cout << "\na: " << a << " b: " << b;
	return 0;
}