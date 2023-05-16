#pragma once
#include "Figure.h"

class Rectangle :public Figure {
private:
	std::string name{ "RECTANGLE" };
	double height = 0;
	double width = 0;
	double squareWidth = 0;
	double squareHeight = 0;

public:
	Rectangle();
	Rectangle(const std::string& name, double height,double width, const Figure& figure);

	double square()const;
	double squareOutside()const;
	static Rectangle defaultRectangle(const std::string& name);

	friend std::ostream& operator<<(std::ostream& ostream, const Rectangle& Rectangle);
};