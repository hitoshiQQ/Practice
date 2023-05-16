#include <iostream>
#include "circle.h"
#include "triangle.h"
#include "square.h"
#include "rectangle.h"
#include "Enter.h"

int main() {

	std::string command;
	do {
		std::cout << "Enter figure [circle,triangle,square,rectangle]: ";
		command = getCommand();
		if (command == "circle") {
			Circle circle = Circle::defaultCircle("\nÑircle: ");
			std::cout << circle << std::endl;
		}else if (command == "triangle") {
			Triangle triangle = Triangle::defaultTriangle("\nTriangle: ");
			std::cout << triangle << std::endl;
		}else if (command == "square") {
			Square square = Square::defaultSquare("\nSquare: ");
			std::cout << square << std::endl;
		}else if (command == "rectangle") {
			Rectangle rectangle = Rectangle::defaultRectangle("\nRectangle: ");
			std::cout << rectangle << std::endl;
		}else if (command != "exit") {
			std::cout << "Incorrcet command.Try again!";
		}
	} while (command != "exit");

}