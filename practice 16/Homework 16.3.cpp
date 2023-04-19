#include "Source.h"
#include <sstream>
#include <cassert>


void calc_process(std::stringstream& buffer_stream, double& res) {
	double num1, num2;
	char action;

	buffer_stream >> num1 >> action >> num2;

	switch (action) {
	case '+':
		res = num1 + num2;
		break;

	case '-':
		res = num1 - num2;
		break;

	case '*':
		res = num1 * num2;
		break;

	case '/':
		if (num2 == 0) {
			std::cerr << "\n\t\t!Error Divide by Zero!\n";
			assert(num2 != 0);
		}
		res = num1 / num2;
		break;

	default:
		std::cout << "\n\tIncorrect input!\n";
		assert(false);
	}

	std::cout << "\t\tResult: " << res;
}

int main() {
	std::cout << "\t\tCalculator\n\n";

	std::string buffer;

	std::cout << "Enter expression: ";
	std::cin >> buffer;

	std::stringstream buffer_stream(buffer);

	double res;
	calc_process(buffer_stream, res);
	
	return 0;
}