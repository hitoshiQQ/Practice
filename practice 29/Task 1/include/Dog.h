#pragma once
#include <iostream>
#include <vector>
#include <string>

class Dog {
private:
	std::string name;
	std::vector<Talent*> talents;

public:
	Dog(std::string _name) : name(_name) {};
	~Dog() {};

	void addTalent(Talent* talent) {
		talents.push_back(talent);
	}

	void show_talents() {
		std::cout << "This is " << name << " has some talents: \n";

		for (int j = 0; j < talents.size(); ++j) {
			std::cout << "Can: ";
			talents[j]->showTalent();
			std::cout << std::endl;
		}
	}
};




