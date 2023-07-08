#include "Rectangle.h"
#include <string>

double height = 0;
double width = 0;

std::string Rectangle::type() {
	std::string str = "Rectangle";
	return str;
}

double Rectangle::square() {
	return height * width;
}

BoundingBox Rectangle::dimensions() {
	BoundingBox side_sq;
	side_sq.heigth = height + 0.01;
	side_sq.width = width + 0.01;
	return side_sq;
}

Rectangle::Rectangle(double _h, double _w) : height(_h), width(_w) {};