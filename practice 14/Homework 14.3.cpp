#include "Source.h"
#include <vector>

void print_matrix(std::vector<std::vector<int>> m1) {
	for (int j = 0; j < 4; ++j) {
		for (int i = 0; i < 4; ++i) {
			std::cout << m1[j][i] << " ";
		}
		std::cout << std::endl;
	}
}

std::vector<std::vector<int>> input_matrix(std::vector<std::vector<int>> m1) {
	for (int j = 0; j < 4; ++j) {
		for (int i = 0; i < 4; ++i) {
			std::cin >> m1[j][i];
		}
	}
	return m1;
}

bool is_check_equals(std::vector<std::vector<int>> m1, std::vector<std::vector<int>> m2) {
	for (int j = 0; j < 4; ++j) {
		for (int i = 0; i < 4; ++i) {
			if (m1[j][i] != m2[j][i])
				return false;
		}
	}
	return true;
	
}

std::vector<std::vector<int>> diagonal_matrix(std::vector<std::vector<int>> m1) {
	for (int j = 0; j < 4; ++j) {
		for (int i = 0; i < 4; ++i) {
			if (j != i)
				m1[j][i] = 0;
		}
	}
	return m1;
}


int main() {

	std::cout << "\t\t Matrix\n";

	std::vector<std::vector<int>> m1 = { {1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16} };
	
	std::vector<std::vector<int>> m2 = { {1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16} };

	std::cout << "\nEnter first matrix: ";
	input_matrix(m1);
	std::cout << "\nEnter second matrix: ";
	input_matrix(m2);

	if (is_check_equals(m1, m2)) {
		std::cout << "\b Equal!\n";
		m1 = diagonal_matrix(m1);
	}
	else {
		std::cout << "\nisn't equal!\n";
	}
	print_matrix(m1);


	return 0;
}