#include <iostream>
#include "arithmetic.h"

int main() {

	AverageArithmeticMean<int> arr0({ 1,2,3,4,5,12,13,76 });
	arr0.show();
	arr0.averageCalculation();

	std::cout << "\n\n\n";

	AverageArithmeticMean<float> arr1({ 1.1f,2.2f,3.3f,4.4f,5.5f,6.6f,7.7f,8.8f });
	arr1.show();
	arr1.averageCalculation();

	std::cout << "\n\n\n";

	AverageArithmeticMean<double> arr2({ 23.42, 123.54, 3.123, 32.123, 34.2, 123.231, 123.23, 1.001 });
	arr2.show();
	arr2.averageCalculation();

	std::cout << "\n\n\n";

	arr0.enter();
	arr0.show();
	arr0.averageCalculation();

	return 0;
}