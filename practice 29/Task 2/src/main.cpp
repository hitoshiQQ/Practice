#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "printParams.h"

int main() {

	Circle c(3);
	printParams(&c);

	Triangle t(4, 5, 6);
	printParams(&t);

	Rectangle r(7, 8);
	printParams(&r);

	return 0;
}