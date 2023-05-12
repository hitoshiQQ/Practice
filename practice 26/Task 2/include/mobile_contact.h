#pragma once
#include <string>
#include <iostream>

class Contact {
	std::string name;
	std::string number;

public:
	std::string enterName() {
		std::cout << "Enter name: ";
		std::string enter;
		std::cin >> enter;
		name = enter;
		return enter;
	}

	static std::string enterNumString() {
		std::string enter;
		std::cin >> enter;
		return enter;
	}

	static bool checkNum(std::string num) {
		for (int j = 0; j < num.size(); ++j) {
			if (num[j] > '9' || num[j] < '0') {
				return false;
			}
		}
		return true;
	}


	void enterNumber() {
		while (true) {
			std::cout << "\nEnter number: ";
			std::string enter = enterNumString();
			if (checkNum(enter)) {
				number = enter;
				break;
			}else {
				std::cout << "Incorrecty input.Try again!\n";
			}
		}
	}

	std::string getName() {
		return name;
	}
	std::string getNumber() {
		return number;
	}

	void setName(std::string name_new) {
		name = name_new;
	}
	void setNumber(std::string num_new) {
		if (checkNum(num_new)) {
			number = num_new;
		}
		number = "0";
	}

};