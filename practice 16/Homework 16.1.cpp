#define _CRT_SECURE_NO_WARNINGS
#include "iostream"

int main() {
	std::cout << "\t\tSpeedometer\n\n";
	float speed{ 0 }, d;

	do {
		std::cout << "\nEnter delta of speed: ";
		std::cin >> d;

		speed += d;

		if (speed >150) {
			speed = 150.;
		}else if(speed < 0){
			speed = 0;
		}
		char buffer[5];
		std::sprintf(buffer, "%.1f", speed);
		std::cout << "Current speed: " << buffer;

	} while (!(speed>-0.01 && speed < 0.01));

	std::cout << "\n\n\t\t\t!Stopped!";

	return 0;
}