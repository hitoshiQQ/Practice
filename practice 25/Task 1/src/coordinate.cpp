#include "coordinate.h"
#include <iostream>
#include <cmath>

double const COORDINATE_CONST = 0.0001;

bool checkEqual(Coordinate& first, Coordinate& second) {
	if (fabs(first.x - second.x) <= COORDINATE_CONST &&
		fabs(first.y - second.y) <= COORDINATE_CONST) {
		return true;
	}
	return false;
}

Coordinate enterCoordinate(std::string str) {
	Coordinate new_coordinate;
	std::cout << str << " ";
	new_coordinate.x = enterInt("X: ");
	std::cout << str << " ";
	new_coordinate.y = enterInt("Y: ");
	return new_coordinate;
}

bool checkLine(std::vector<Coordinate> c1, std::vector<Coordinate> c2) {
	if (c1.size() < 2 || c2.size() < 2) {
		return false;
	}
	if ((checkEqual(c1.at(0), c2.at(0)) && checkEqual(c1.at(1), c2.at(1)))
		|| (checkEqual(c1.at(0), c2.at(1)) && checkEqual(c1.at(1), c2.at(0)))) {
		return true;
	}
	return false;
}

bool checkPointLine(Coordinate& const lineX, Coordinate& const lineY, Coordinate& const Point) {
	double a = lineX.x - lineY.x;
	double b = lineX.y - lineY.y;
	double c = lineX.x - Point.x;
	double d = lineX.y - Point.y;
	return ((fabs(c) <= fabs(a)) && fabs((a * d) - (c * b)) <= COORDINATE_CONST);
}

void printCoordinate(Coordinate& coordinate) {
	std::cout << "\n| Coordinate: " << coordinate.x << ":" << coordinate.y << std::endl;
}