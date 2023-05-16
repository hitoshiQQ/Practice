#include "Figure.h"

Figure::Figure() = default;

Figure::Figure(const Coordinate& center, Color color) {
	this->center = center;
	this->color = color;
}

const Coordinate& Figure::getCenter() const {
	return center;
}
Color Figure::getColor() const {
	return color;
}

void Figure::setCenter(const Coordinate& _center) {
	this->center = _center;
}
void Figure::setColor(Color _color) {
	this->color = _color;
}

std::ostream& operator<<(std::ostream& ostream, const Color& colors) {
	std::string color;
	switch (colors) {
	   case 1: {
		   color = "RED";
		   break;
	   }
	   case 2: {
		   color = "BLUE";
		   break;
	   }
	   case 3: {
		   color = "GREEN";
		   break;
	   }
	   case 4: {
		   color = "PINK";
		   break;
	   }
	   default: {
		   color = "NONE";
	   }
	}
	ostream << color;
	return ostream;
}