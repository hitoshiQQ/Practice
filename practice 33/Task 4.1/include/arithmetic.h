#pragma once
#include <iostream>

template <typename T>
T enter(T* arr,size_t size = 8) {
	std::cout << "\nEnter " << size << " value array: ";
	for (int j = 0; j < size; ++j) {
		T val;
		std::cin >> val;
		arr[j] = val;
	}
	return *arr;
}

template <typename T>
void show(T* arr, size_t size = 8) {
	std::cout << "\nArray: ";
	for (int j = 0; j < size; ++j) {
		if (j > 0) {
			std::cout << " + " << arr[j];
		}else {
			std::cout << arr[j];
		}
	}
	std::cout << std::endl;
}

template <typename T>
T averageCalculation(T* arr, size_t size = 8) {
	T av = 0;
	for (int j = 0; j < size; ++j) {
		av += arr[j];
	}
	return (av / size);
}
