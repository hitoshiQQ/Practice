#pragma once
#include "Figure.h"

class Square :public Figure {
private:
	std::string name{ "SQUARE" };
	double squareSide = 0;
	double squareAroundOutside = 0;

public:
	Square();
	Square(const std::string& name, double side, const Figure& figure);

	double square()const;
	double squareOutside()const;
	static Square defaultSquare(const std::string& name);

	friend std::ostream& operator<<(std::ostream& ostream, const Square& square);
};