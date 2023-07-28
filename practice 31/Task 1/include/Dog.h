#pragma once
#include <iostream>
#include <memory>
#include "Toy.h"

class Dog {
private:
	std::string name;
	int age;
	std::shared_ptr<Toy> lovelyToy;

public:
	Dog(std::string _name, std::shared_ptr<Toy> toy, int _age) : name(_name), lovelyToy(toy) {
		if (_age >= 0 && _age < 30) {
			age = _age;
		}
	}
	Dog() : Dog("Barbos", std::make_shared<Toy>("SomeToy"), 0) {};
	Dog(std::string _name) : Dog(_name, std::make_shared<Toy>("SomeToy"), 0) {};
	Dog(int _age) : Dog("Barbos", std::make_shared<Toy>("SomeToy"), _age) {};
	~Dog() {
		std::cout << "\n\nDog " << name << " is deleted";
	}

	void copyToy(const Dog& oth) {
		lovelyToy = oth.lovelyToy;
	}

	void getToy(std::shared_ptr<Toy>& _toy) {
		if (_toy == lovelyToy && lovelyToy.use_count() == 2) {
			std::cout << "\nI already have this toy!";
			return;
		}
		if (_toy != lovelyToy && _toy.use_count() > 1) {
			std::cout << "\nAnother dog is playing with this toy!";
			return;
		}
		lovelyToy.reset();
		lovelyToy = _toy;
		std::cout << "\nPick up a toy!";
	}
	void dropToy() {
		if (lovelyToy == nullptr) {
			std::cout << "\nNothing to drop!";
			return;
		}
		lovelyToy.reset();
		lovelyToy = nullptr;
		std::cout << "\n" << name << " dropped toy!";
	}
};