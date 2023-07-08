#include "Triangle.h"
#include <cmath>
#include <string>
//
#include <iostream>

double a = 0;
double b = 0;
double c = 0;
double p = 0;



std::string Triangle::type() {
	std::string str = "Triangle";
	return str;
}

double Triangle::square() {
	p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

BoundingBox Triangle::dimensions() {
	p = (a + b + c) / 2;
	double rad_circle_described = a * b * c / (4 * sqrt(p * (p - a) * (p - b) * (p - c)));
	BoundingBox side_sq;
	side_sq.width = 2 * rad_circle_described;
	side_sq.heigth = side_sq.width;
	
	return side_sq;
}

Triangle::Triangle(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {};

