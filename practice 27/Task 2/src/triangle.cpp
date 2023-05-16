#include "triangle.h"
#include <random>

Triangle::Triangle() = default;

Triangle::Triangle(const std::string& name, double side, const Figure& figure) {
	this->name = name;
	this->side = side;
	this->squareHeight = side * (sqrt(3) / 2) + 0.1;
	this->squareWidth = side + 0.1;
	this->setCenter(figure.getCenter());
	this->setColor(figure.getColor());
}

double Triangle::square()const {
	return pow(side, 2) * (sqrt(3) / 4);
}

double Triangle::squareOutside()const {
	return squareHeight * squareWidth;
}

Triangle Triangle::defaultTriangle(const std::string& name) {
	std::random_device _r;
	std::mt19937 generate(_r());
	std::uniform_real_distribution<> _side(5., 10.);
	std::uniform_real_distribution<> _x(0., 20.);
	std::uniform_real_distribution<> _y(0., 20.);
	std::uniform_real_distribution<> _color(0, 4);

	Figure figure(Figure{{_x(generate),_y(generate)},(Color)_color(generate) });
	Triangle triangle(name, _side(generate), figure);
	return triangle;
}

std::ostream& operator<<(std::ostream& ostream, const Triangle& triangle) {
    std::string color;
	switch (triangle.getColor()) {
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
	ostream << "Figure name: " << triangle.name << std::endl;
	ostream << "Coordinate figure center: " << triangle.getCenter().x << ":" <<
		triangle.getCenter().y << std::endl;
	ostream << "Figure color: " << color << std::endl;
	ostream << "Triangle side: " << triangle.side << std::endl;
	ostream << "Triangle square: " << triangle.square() << std::endl;
	ostream << "The area of the describing rectangle: " << triangle.squareOutside() << std::endl;
	ostream << "The height of the describing rectangle: " << triangle.squareHeight << std::endl;
	ostream << "The width  of the describing rectangle: " << triangle.squareWidth << std::endl;
	return ostream;
}