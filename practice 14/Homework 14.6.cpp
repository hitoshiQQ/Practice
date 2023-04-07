#include "Source.h"

void initialization(int arr[][5]) {
	for (int j = 0; j < 25; ++j) {
		arr[j / 5][((j / 5 + 1) % 2 * j + (j / 5 % 2) * (24 - j))%5] = j;
	}
}

void print(int arr[][5]) {
	for (int j = 0; j < 5; ++j) {
		for (int i = 0; i < 5; ++i) {
			std::cout << arr[j][i] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {

	std::cout << "\t\t\n\n";

	int arr[5][5];
	initialization(arr);
	print(arr);
	
	return 0;
}