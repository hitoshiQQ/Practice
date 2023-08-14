#pragma once
#include <iostream>
#include <vector>

template <typename T>
class AverageArithmeticMean {
private:
	std::vector<T> list;
	size_t size = 8;

public:
	AverageArithmeticMean() = default;
	explicit AverageArithmeticMean(size_t arr_size) : size(arr_size) {}
	explicit AverageArithmeticMean(const std::vector<T>& list) : list(list) {
		size = list.size();
	}

	virtual ~AverageArithmeticMean() {
		list.clear();
	}

	void enter();
	void show();
	T averageCalculation();
};

template <typename T>
void AverageArithmeticMean<T>::enter() {
	list.clear();
	std::cout << "\nEnter " << size << " value array: ";
	for (int j = 0; j < size; ++j) {
		T val;
		std::cin >> val;
		list.push_back(val);
	}
}

template <typename T>
void AverageArithmeticMean<T>::show() {

	std::cout << "\nArray: \n";
	T amount = 0;
	for (T digit : list) {
		amount += digit;
		if (amount != digit) {
			std::cout << " + " << digit;
		}else {
			std::cout << digit;
		}
	}
	std::cout << " = " << amount << std::endl;
}

template <typename T>
T AverageArithmeticMean<T>::averageCalculation() {
	T av = 0;
	for (T digit : list) {
		av += digit;
	}
	return (av / size);
}

	

