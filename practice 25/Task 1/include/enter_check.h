#pragma once
#include <iostream>
#include <string>

enum Type {
	INT_T = 0,
	DOUBLE_T
};

std::string enterString(const std::string& const str);

bool checkDigit(std::string str, Type type);

int enterInt(const std::string& const str);

double enterDouble(const std::string& const str);