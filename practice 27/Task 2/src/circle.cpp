#include <cmath>
#include <random>
#include "circle.h"

Circle::Circle() = default;

Circle::Circle(const std::string& name, double rad, const Figure& figure) {
	this->name = name;
	this->rad = rad;
	this->squareAroundOutside = 2 * rad + 0.1;
	this->setCenter(figure.getCenter());
	this->setColor(figure.getColor());
}

double Circle::square() const {
	return (M_PI * rad * rad);
}

double Circle::squareOutside() const {
	return pow(squareAroundOutside, 2);
}

Circle Circle::defaultCircle(const std::string& name) {
	std::random_device _r;
	std::mt19937 generate(_r());
	std::uniform_real_distribution<> _rad(5., 10.);
	std::uniform_real_distribution<> _x(0., 20.);
	std::uniform_real_distribution<> _y(0., 20.);
	std::uniform_real_distribution<> _color(0, 4);

	Figure figure(Figure{{_x(generate),_y(generate)},(Color)_color(generate) });
	Circle circle(name, _rad(generate), figure);
	return circle;
}

std::ostream& operator<<(std::ostream& ostream, const Circle& circle) {
	std::string color;
	switch (circle.getColor()) {
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
	ostream << "Figure name: " << circle.name << std::endl;
	ostream << "Coordinate figure center: " << circle.getCenter().x << ":" <<
		circle.getCenter().y << std::endl;
	ostream << "Figure color: " << color << std::endl;
	ostream << "Circle radius: " << circle.rad << std::endl;
	ostream << "Circle square: " << circle.square() << std::endl;
	ostream << "The area of the describing rectangle: " << circle.squareOutside() << std::endl;
	ostream << "The height of the describing rectangle: " << circle.squareAroundOutside << std::endl;
	ostream << "The width  of the describing rectangle: " << circle.squareAroundOutside << std::endl;
	return ostream;
}

