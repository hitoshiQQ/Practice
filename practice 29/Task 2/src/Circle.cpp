#define _USE_MATH_DEFINES
#include "Circle.h"
#include <cmath>
#include <string>

double rad = 0;

std::string Circle::type() {
	std::string str = "Circle";
	return str;
}

double Circle::square() {
	return M_PI * (rad * rad);
}

BoundingBox Circle::dimensions() {
	BoundingBox side_sq;
	side_sq.width = 2 * rad;
	side_sq.heigth = side_sq.width;
	
	return side_sq;
}

Circle::Circle(double _rad) : rad(_rad) {};