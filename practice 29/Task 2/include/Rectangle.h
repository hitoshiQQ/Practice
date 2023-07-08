#pragma once
#include "Shape.h"

class Rectangle :public Shape {
private:
	double height;
	double width;

	std::string type() override;
	double square() override;
	BoundingBox dimensions() override;

public:
	Rectangle(double _h, double _w);
};