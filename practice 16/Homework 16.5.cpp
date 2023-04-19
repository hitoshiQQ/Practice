#include "Source.h"
#include <sstream>


enum switches {

	LIGHTS_INSIDE = 1,
	LIGHTS_OUTSIDE = 2,
	HEATERS = 4,
	WATER_PIPE_HEATING = 8,
	CONDITIONER = 16
};




int main() {
	std::cout << "\t\tSmart Home\n\n";

	int day{ 1 }, hours{ 0 };

	int temp_Inside, temp_Outside;
	bool movement_Outside, is_light_turnOn;
	int switches_state = 0 , colorOfTemp {5000};

	while (day <= 2) {
		hours = 0;
		while (hours <= 23) {
			std::cout << "\nCurrent day: " << day << std::endl;
			std::cout << "\nCurrent time: ";
			if (hours < 10) {
				std::cout << "0";
			}
			std::cout << hours << ":00\n\n";

			std::cout << "Enter INFO : \nTemperature outside \nTemperature inside " <<
				"\nMovement outside \n [Enter number, if is not zero movement] " <<
				"\n Light's turnde ON.\n";
			std::string info;
			std::getline(std::cin, info);
			std::stringstream temp_stream(info);

			std::string tempOutside, tempInside, movementOutside, lightTurnOn;

			temp_stream >> tempOutside >> tempInside >> movementOutside >> lightTurnOn;

			temp_Outside = std::stoi(tempOutside);
			temp_Inside = std::stoi(tempInside);

			if (std::stoi(movementOutside) != 0) {
				movement_Outside = true;
			} else {
				movement_Outside = false;
			}

			if (std::stoi(lightTurnOn) != 0) {
				is_light_turnOn = true;
			} else {
				is_light_turnOn = false;
			}

			// Water Pipe Heating 
			if ((temp_Outside < 0) && !(switches_state & WATER_PIPE_HEATING)) {
				std::cout << "Water pipe turned ON!\n";
				switches_state |= WATER_PIPE_HEATING;
			}

			if ((temp_Outside > 5) && (switches_state & WATER_PIPE_HEATING)) {
				std::cout << "Water pipe turned OFF!\n";
				switches_state &= ~WATER_PIPE_HEATING;
			}

			// Lights Outside 
			if (((hours > 16) || (hours < 5)) && (movement_Outside) 
				&& !(switches_state & LIGHTS_OUTSIDE)) {
				std::cout << "Light's outside turned ON!\n";
				switches_state |= LIGHTS_OUTSIDE;
			}
			if ((((hours > 16) || (hours < 5)) && (!movement_Outside) && (switches_state & LIGHTS_OUTSIDE)) 
			|| ((hours >16)||(hours < 5)) && (switches_state & LIGHTS_OUTSIDE)){
				std::cout << "Light's outside turned ON!\n";
				switches_state &= ~LIGHTS_OUTSIDE;
			}

			//Heaters
			if ((temp_Inside < 22) && !(switches_state & HEATERS)) {
				std::cout << "Heaters turned ON!\n";
				switches_state |= HEATERS;
			}
			if ((temp_Inside >= 25) && (switches_state & HEATERS)) {
				std::cout << "Heaters turned ON!\n";
				switches_state &= ~HEATERS;
			}

			//Conditioner
			if ((temp_Inside >= 30) && !(switches_state & CONDITIONER)) {
				std::cout << "Conditioner turned ON!\n";
				switches_state |= CONDITIONER;
			}
			if ((temp_Inside <= 25) && (switches_state & CONDITIONER)) {
				std::cout << "Conditioner turned OFF!\n";
				switches_state &= ~CONDITIONER;
			}

			// Light's inside
			if ((is_light_turnOn) && !(switches_state & LIGHTS_INSIDE)) {
				std::cout << "Light's inside turnde ON!\n";
				switches_state |= LIGHTS_INSIDE;
			}
			if ((!is_light_turnOn) && (switches_state & LIGHTS_INSIDE)) {
				std::cout<< "Light's inside turnde OFF!\n";
				switches_state &= ~LIGHTS_INSIDE;
			}

			//Light's 
			if ((hours > 16) && (hours <= 20)) {
				colorOfTemp -= 575;
			}

			if ((hours > 0) && (hours <= 16)) {
				colorOfTemp = 5000;
			}

			if ((switches_state & LIGHTS_OUTSIDE) || (switches_state & LIGHTS_INSIDE)) {
				std::cout << "Color of temperature: " << colorOfTemp<<"K\n\n";
			}
		}
		day++;
	}


	return 0;
}