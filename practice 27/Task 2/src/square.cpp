#include "square.h"
#include <random>

Square::Square() = default;

Square::Square(const std::string& name, double squareSide, const Figure& figure) {
	this->name = name;
	this->squareSide = squareSide;
	this->squareAroundOutside = squareSide + 0.1;
	this->setCenter(figure.getCenter());
	this->setColor(figure.getColor());
}

double Square::square()const {
	return squareSide * squareSide;
}

double Square::squareOutside () const {
	return squareAroundOutside * squareAroundOutside;
}

Square Square::defaultSquare(const std::string& name) {
	std::random_device _r;
	std::mt19937 generate(_r());
	std::uniform_real_distribution<> _side(5., 10.);
	std::uniform_real_distribution<> _x(0., 20.);
	std::uniform_real_distribution<> _y(0., 20.);
	std::uniform_real_distribution<> _color(0, 4);

	Figure figure(Figure{ {_x(generate),_y(generate)},(Color)_color(generate) });
	Square square(name, _side(generate), figure);
	return square;
}

std::ostream& operator<<(std::ostream& ostream, const Square& square) {
	std::string color;
	switch (square.getColor()) {
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
	ostream << "Figure name: " << square.name << std::endl;
	ostream << "Coordinate figure center: " << square.getCenter().x << ":" <<
		square.getCenter().y << std::endl;
	ostream << "Figure color: " << color << std::endl;
	ostream << "Square side: " << square.squareSide << std::endl;
	ostream << "Square square: " << square.square() << std::endl;
	ostream << "The area of the describing rectangle: " << square.squareOutside() << std::endl;
	ostream << "The height of the describing rectangle: " << square.squareAroundOutside << std::endl;
	ostream << "The width  of the describing rectangle: " << square.squareAroundOutside << std::endl;
	return ostream;
}