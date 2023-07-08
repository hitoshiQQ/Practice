#pragma once
#include "BoundingBoxDimensions.h"
#include "string"

class Shape {
public:
	virtual std::string type();
	virtual double square();
	virtual BoundingBox dimensions();
	
};