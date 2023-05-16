#pragma once
#include "Figure.h"

class Triangle : public Figure {
private:
	std::string name{ "TRIANGLE" };
	double side = 0;
	double squareWidth = 0;
	double squareHeight = 0;

public:
	Triangle();
	Triangle(const std::string& name, double side, const Figure& figure);

	double square()const;
	double squareOutside()const;
	static Triangle defaultTriangle(const std::string& name);

	friend std::ostream& operator<<(std::ostream& ostream, const Triangle& triangle);
};