#include "Source.h"

bool is_equal_zero(float num, float accuracy) {
	return ((num - accuracy <= 0) && (0 <= num + accuracy)) || (num < 0);
}

bool is_max_speed(float speed, float accuracy) {
	return (speed >= 150 - accuracy) || (speed + accuracy >= 150)
		|| (speed - accuracy <= 150);
}


int main() {
	std::cout << "\t\tSpeedometer\n\n";
	float speed{ 0 }, d;

	do {
		std::cout << "Enter delta of speed: ";
		std::cin >> d;

		speed += d;

		if (is_max_speed(speed, 0.01)) {
			speed = 150;
		}
		if (is_equal_zero(speed, 0.01)) {
			std::cout<<"Speed is 0\n";
		}else {
			char buffer[5];
			std::sprintf(buffer, "%.1f", speed);
			std::cout << "Current speed: " << buffer;
		}
	} while (!is_equal_zero(speed, 0.01));

	std::cout << "\n\n\t\t\t!Stopped!";

	return 0;
}