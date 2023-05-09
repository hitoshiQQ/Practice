#pragma once
#include "enter_check.h"
#include <vector>

struct Coordinate {
	double x;
	double y;
};

bool checkEqual(Coordinate& first, Coordinate& second);

Coordinate enterCoordinate(std::string str);

bool checkLine(std::vector<Coordinate> c1, std::vector<Coordinate> c2);

bool checkPointLine(Coordinate& const lineX, Coordinate& const lineY, Coordinate& const Point);

void printCoordinate(Coordinate& coordinate);