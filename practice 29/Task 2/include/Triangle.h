#pragma once
#include "Shape.h"

class Triangle : public Shape {
private:
	double a;
	double b;
	double c;
	double p;

	std::string type() override;
	double square() override;
	BoundingBox dimensions() override;

public:
	Triangle(double _a, double _b, double _c);
};
