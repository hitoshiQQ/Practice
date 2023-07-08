#include "Triangle.h"
#include <cmath>
#include <string>

double a = 0;
double b = 0;
double c = 0;
double per = (a + b + c) / 2;

std::string Triangle::type() {
	std::string str = "Triangle";
	return str;
}

double Triangle::square() {
	return sqrt(per * (per - a) * (per - b) * (per - c));
}

BoundingBox Triangle::dimensions() {
	double rad_circle_described = a * b * c / (4 * sqrt(per * (per - a) * (per - b) * (per - c)));
	BoundingBox side_sq;
	side_sq.width = 2 * rad_circle_described;
	side_sq.heigth = side_sq.width;
	
	return side_sq;
}

Triangle::Triangle(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {};

