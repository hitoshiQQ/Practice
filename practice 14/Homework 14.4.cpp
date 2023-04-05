#include "Source.h"
#include <vector>

std::vector<std::vector<float>> input_matrix(int row, int col) {
	std::vector<std::vector<float>> m1(row);
	for (int j = 0; j < row; ++j) {
		m1[j].resize(col);
		for (int i = 0; i < col; ++i) {
			std::cin >> m1[j][i];
		}
	}
	return m1;
}

std::vector<float> input_vector(int row) {
	std::vector<float>vec(row);
	for (int j = 0; j < row; ++j) {
		std::cin >> vec[j];
	}
	return vec;
}

std::vector<float> multiply(std::vector<std::vector<float>> m1, std::vector<float>vec) {
	std::vector<float> vec_mp(vec.size()); float mpl{ 0 };
	for (int j = 0; j < m1.size(); ++j) {
		mpl = 0;
		for (int i = 0; i < m1.size(); ++i) {
			mpl += m1[j][i] * vec[i];
		}
		vec_mp[j] = mpl;
	}
	return vec_mp;
}

void print_vector(std::vector<float> vec) {
	for (int j = 0; j < vec.size(); ++j) {
		std::cout << vec[j] << std::endl;
	}
}

int main() {

	std::cout << "\t\t Matrix multiply\n";

	std::vector<float> vec;
	std::vector<std::vector<float>> matrix;

	std::cout << "\nEnter matrix: ";
	matrix = input_matrix(4, 4);
	std::cout << "\nEnter vec: ";
	vec = input_vector(4);

	std::vector<float> vec_mp = multiply(matrix, vec);
	std::cout << "\nResult: ";
	print_vector(vec_mp);

	return 0;
}