#include "rectangle.h"
#include <random>

Rectangle::Rectangle() = default;

Rectangle::Rectangle(const std::string& name, double height, double width, const Figure& figure) {
	this->name = name;
	this->height = height;
	this->width = width;
	this->squareHeight = height + 0.1;
	this->squareWidth = width + 0.1;
	this->setCenter(figure.getCenter());
	this->setColor(figure.getColor());
}

double Rectangle::square()const {
	return height * width;
}

double Rectangle::squareOutside()const {
	return squareHeight * squareWidth;
}

Rectangle Rectangle::defaultRectangle(const std::string& name) {
	std::random_device _r;
	std::mt19937 generate(_r());
	std::uniform_real_distribution<> _h(5., 10.);
	std::uniform_real_distribution<> _w(5., 10.);
	std::uniform_real_distribution<> _x(0., 20.);
	std::uniform_real_distribution<> _y(0., 20.);
	std::uniform_real_distribution<> _color(0, 4);

	Figure figure(Figure{ {_x(generate),_y(generate)},(Color)_color(generate) });
	Rectangle rectangle(name,_h(generate), _w(generate), figure);
	return rectangle;
}

std::ostream& operator<<(std::ostream& ostream, const Rectangle& rectangle) {
	std::string color;
	switch (rectangle.getColor()) {
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
	ostream << "Figure name: " << rectangle.name << std::endl;
	ostream << "Coordinate figure center: " << rectangle.getCenter().x << ":" <<
		rectangle.getCenter().y << std::endl;
	ostream << "Figure color: " << color << std::endl;
	ostream << "Rectangle height: " << rectangle.height << std::endl;
	ostream << "Rectangle width: " << rectangle.width << std::endl;
	ostream << "Square rectangle: " << rectangle.square() << std::endl;
	ostream << "The area of the describing rectangle: " << rectangle.squareOutside() << std::endl;
	ostream << "The height of the describing rectangle: " << rectangle.squareHeight << std::endl;
	ostream << "The width  of the describing rectangle: " << rectangle.squareWidth << std::endl;
	return ostream;
}