#include "Source.h"
#include <string>

int main() {
	std::cout << "\t\tFractional number stitcher\n\n";
	std::string first_half, second_half;
	
	std::cout << "Enter whole part of number: ";
	std::cin >> first_half;

	std::cout << "Enter whole fractional of number: ";
	std::cin >> second_half;

	double num = stod(first_half + '.' + second_half);
	std::cout << "Your number: " << num;

	return 0;
}