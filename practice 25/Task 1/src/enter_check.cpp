#include "enter_check.h"

std::string enterString(const std::string& const str) {
	std::string enter;
	std::cout << str;
	std::getline(std::cin, enter);
	return enter;
}

bool checkDigit(std::string str, Type type) {
	switch (type) {
	   case INT_T: {
		   for (int j = 0; j < str.size(); ++j) {
			   if (str[j] > '9' || str[j] < '-' || str[j] == '.' || str[j] == '/') {
				   return false;
			   }
		   }
		   break;
       }
	   case DOUBLE_T: {
		   for (int j = 0; j < str.size(); ++j) {
			   if (str[j] > '9' || str[j] < '-' || str[j] == '/') {
				   return false;
			   }
		   }
		   break;
	   }
	   default:
		   return false;
	}
	return true;
}

int enterInt(const std::string& const str) {
	int enter = -1;
	std::string enter_str = enterString(str);
	if (checkDigit(enter_str, INT_T)) {
		enter = std::stoi(enter_str);
	}
	return enter;
}

double enterDouble(const std::string& const str) {
	int enter = -1;
	std::string enter_str = enterString(str);
	if (checkDigit(enter_str, DOUBLE_T)) {
		enter = std::stoi(enter_str);
	}
	return enter;
}