#pragma once
#include <iostream>

class Toy {
private:
	std::string name;

public:
	Toy(std::string _name) : name(_name) {};
	Toy() : name("SomeToy") {};
};