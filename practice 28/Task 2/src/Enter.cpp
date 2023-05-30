#include "Enter.h"

bool Validator::checkNumInt(std::string str) {
	for (int j = 0; j < str.size(); ++j) {
		if (j == 0 && str[j] == '-') {
			continue;
		}
		if (str[j] > '9' && str[j] < '0') {
			return false;
		}
	}
	return true;
}

bool Validator::checkRealNum(std::string str) {
	bool aDot = false;
	for (int j = 0; j < str.size(); ++j) {
		if (str[j] == '.' && aDot) {
			return false;
		}
		else if (str[j] == '.' && !aDot) {
			aDot = true;
			continue;
		}
		if (j == 0 && str[j] == '-') {
			continue;
		}
		if (str[j] > '9' && str[j] < '0') {
			return false;
		}
	}
	return true;
}



std::mutex Enters::access;

double Enters::enterDouble(const std::string& str) {
	access.lock();
	std::string enter = " ";
	bool isntNum = true;
	while (isntNum) {
		std::cout << str;
		std::cin >> enter;
		isntNum = !Validator::checkRealNum(enter);
		if (isntNum) {
			std::cout << "\nIncorrcet input.Tru again\n";
		}
		else {
			break;
		}
	}
	access.unlock();
	return std::stod(enter);
}

int Enters::enterInt(const std::string& str) {
	access.lock();
	std::string enter = " ";
	bool isntNum = true;
	while (isntNum) {
		std::cout << str;
		std::cin >> enter;
		isntNum = !Validator::checkNumInt(enter);
		if (isntNum) {
			std::cout << "Try again" << std::endl;
		}
		else {
			break;
		}
	}
	access.unlock();
	return std::stoi(enter);
}

std::string Enters::enterStr(std::string str) {
	access.lock();
	std::string enter;
	std::cout << str;
	std::cin >> enter;
	access.unlock();
	return enter;
}


double Enters::enterPositionDouble(const std::string& str) {
	double res = 0;
	while (res <= 0) {
		res = enterDouble(str);
		if (res < 0) {
			std::cout << "\nEnter number bigger then zero!\n";
		}
	}
	return res;
}

void Enters::print(std::string str) {
	access.lock();
	std::cout << str;
	access.unlock();
}