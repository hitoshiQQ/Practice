#include <iostream>

int jump_amount(int step_all, int step_max) {
	if (step_all < 0) {
		return 0;
	}
	else if (step_all <= 1) {
		return 1;
	}
	else {
		int jumps = 0;
		int step_left = step_all - 1;
		for (int j = 1; j <= step_max && step_left >= 0; ++j) {
			jumps += jump_amount(step_left, step_max);
			--step_left;
		}
		return jumps;
	}
}

int main() {
	std::cout << "\t\tTask 3\n\n";

	int number_of_ways{ 0 }, steps{ 0 }, max_step{ 0 };
	std::cout << "Enter number of step's: ";
	std::cin >> steps;
	std::cout << "Enter number of max range step's :";
	std::cin >> max_step;
	number_of_ways = jump_amount(steps, max_step);
	std::cout << "Number of ways: " << number_of_ways;

	return 0;
}