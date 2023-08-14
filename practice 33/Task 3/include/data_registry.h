#pragma once
#include <iostream>
#include <vector>

template <typename T1, typename T2>
class DataRegistry {
private:
	std::vector<std::pair<T1, T2>> data;

public:
	DataRegistry() = default;

	void add();
	void find();
	void list();
	void remove();
};

template <typename T1, typename T2>
void DataRegistry<T1, T2>::add() {
	std::pair<T1, T2> pair;
	std::cout << "\nEnter the key: ";
	std::cin >> pair.first;
	std::cout << "\nEnter value for key: ";
	std::cin >> pair.second;

	data.push_back(pair);
}

template <typename T1, typename T2>
void DataRegistry<T1, T2>::find() {
	T1 key;
	std::cout << "\nEnter the value of the key: ";
	std::cin >> key;

	int curr = 1;
	int found = 0;
	for (std::pair<T1, T2> pair : data) {
		if (pair.first == key) {
			++found;
			std::cout << "\n# " << curr++ << " || key: " << pair.first << " || key value: "
				<< pair.second << std::endl;
		}
	}
	std::cout << "\nNumber of record's found: " << found << std::endl;
}

template <typename T1, typename T2>
void DataRegistry<T1, T2>::list() {
	if (!data.empty()) {
		int curr = 0;
		std::cout << "\n\t\t\tRegister: ";
		for (std::pair<T1, T2> pair : data) {
			std::cout << "\n# " << ++curr << " || key: " << pair.first << " || key value: "
				<< pair.second << std::endl;
		}
	}
	else {
		std::cout << "\nRegister is empty!";
	}
}

template <typename T1, typename T2>
void DataRegistry<T1, T2>::remove() {
	T1 key;
	std::cout << "\nEnter the value of the key: ";
	std::cin >> key;

	int found = 0;
	typename std::vector<std::pair<T1, T2>>::iterator iter = data.begin();

	while (iter != data.end()) {
		if (iter->first == key) {
			data.erase(iter);
			++found;
		}
		else {
			++iter;
		}
	}
	std::cout << "\nNumber of records found and deleted: " << found << std::endl;
}