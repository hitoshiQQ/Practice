#pragma once
#include "Figure.h"

class Circle : public Figure {
private:
	std::string name{ "CIRCLE" };
	double rad = 0;
	double squareAroundOutside = 0;

public:
	Circle();
	Circle(const std::string& name, double rad, const Figure& figure);

	double square() const;
	double squareOutside() const;
	static Circle defaultCircle(const std::string& name);

	friend std::ostream& operator<<(std::ostream& ostream, const Circle& circle);
};