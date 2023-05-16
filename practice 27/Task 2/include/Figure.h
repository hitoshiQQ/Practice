#pragma once
#include <iostream>
#include "Coordinate_Enum.h"

class Figure {
private:
	Coordinate center{ 0.0,0.0 };
	Color color{ NONE };

public:
	Figure();
	Figure(const Coordinate& center, Color color);

	const Coordinate& getCenter() const;
	Color getColor() const;

	void setCenter(const Coordinate& center);
	void setColor(Color color);

	friend std::ostream& operator<<(std::ostream& ostream, const Color& colors);
};