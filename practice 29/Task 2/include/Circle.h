#pragma once
#include "Shape.h"

class Circle : public Shape {
private:
	double rad;

	std::string type() override;
	double square() override;
	BoundingBox dimensions() override;

public:
	Circle(double _rad);
};