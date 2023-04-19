#include <iostream>
#include <sstream>
#include <string>

enum switches {

	POWER = 1, SOCKETS = 2,
	LIGHTS_INSIDE = 4, LIGHTS_OUTSIDE = 8,
	HEATERS = 16, WATER_PIPE_HEATING = 32,
	CONDITIONER = 64
};

int inside_heaters(int status, int temp) {
	bool startStatus = status & HEATERS;
	if (temp < 22) {
		status |= HEATERS;
	}
	if (temp >= 25) {
		status &= ~HEATERS;
	}
	bool endStatus = status & HEATERS;
	if (startStatus != endStatus) {
		std::cout << "\nHeater's turned " << (status & HEATERS ? "ON!" : "OFF!");
	}
	return status;
}

int water_pipe_heat(int status, int temp) {
	bool startStatus = status & WATER_PIPE_HEATING;
	if (temp < 0) {
		status |= WATER_PIPE_HEATING;
	}else {
		if (temp > 5) {
			status &= ~WATER_PIPE_HEATING;
		}
	}
	bool endStatus = status & WATER_PIPE_HEATING;
	if (startStatus != endStatus) {
		std::cout << "\nWater heater turned " << (status & WATER_PIPE_HEATING ? "ON!" : "OFF!");
	}
	return status;
}

int light_outside(int status, int time, bool move) {
	bool startStatus = status & LIGHTS_OUTSIDE;
	if (move) {
		if (time > 16 || time < 5) {
			status |= LIGHTS_OUTSIDE;
		}
	}else {
		status &= ~LIGHTS_OUTSIDE;
	}

	bool endStatus = status & LIGHTS_OUTSIDE;
	if (startStatus != endStatus) {
		std::cout << "\nLight's outside turned " << (status & LIGHTS_OUTSIDE ? "ON!" : "OFF!");
	}
	return status;
}

int light_inside(int status, int time, bool condition) {
	bool startStatus = status & LIGHTS_INSIDE;
	bool change_flag = false;

	(condition ? status |= LIGHTS_INSIDE : status &= ~LIGHTS_INSIDE);
	int colorOfTemp = 5000;

	if (condition) {
		if (time >= 16 && time <= 20) {
			colorOfTemp -= 460 * (5 - (20 - time));
			change_flag = true;
		}
		if (time > 20 && time < 24) {
			colorOfTemp = 2700;
		}
	}
	std::string statusON = "ON! Color temperature is: ";
	statusON += std::to_string(colorOfTemp);

	bool endStatus = status & LIGHTS_INSIDE;
	if ((startStatus != endStatus) || (condition && (change_flag || time == 0))) {
		std::cout << "\nLight's inside turned " << (status & LIGHTS_INSIDE ? statusON : "OFF!");
	}
	return status;
}

int conditioner(int status, int temp) {
	bool startStatus = status & CONDITIONER;
	if (temp > 30) {
		status |= CONDITIONER;
	}
	if (temp <= 25) {
		status &= ~CONDITIONER;
	}

	bool endStatus = status & CONDITIONER;
	if (startStatus != endStatus) {
		std::cout << "\nConditioner turned " << (status & CONDITIONER ? "ON!" : "OFF!");
	}
	return status;
}

int smart_home_process(int hours, int condition) {
	std::cout<<"\n\n\nHour's is "<<hours <<":00. "<<" Enter INFO : \n\t\t Temperature outside \n\t\t Temperature inside " <<
		"\n\t\t Movement outside (yes/no) " <<"\n\t\t Light's inside (on/off)\n"; 
	std::string info;
	std::getline(std::cin, info);
	std::stringstream temp_stream(info);

	std::string tempOutside, tempInside, movement, lightTurn;
	bool move_flag = false;
	bool light_flag = false;

	temp_stream >> tempOutside >> tempInside >> movement >> lightTurn;
	if (movement == "yes") {
		move_flag = true;
	}
	if (lightTurn == "on") {
		light_flag = true;
	}

	condition = water_pipe_heat(condition, std::stoi(tempOutside));
	condition = light_outside(condition, hours, move_flag);
	condition = inside_heaters(condition, std::stoi(tempInside));
	condition = conditioner(condition, std::stoi(tempInside));
	condition = light_inside(condition, hours, light_flag);

	return condition;
}

int main() {
	int status = 0;
	status |= POWER;status |= SOCKETS;
	std::cout << "\nPOWER turned ON!\nSOCKETS turned ON!\n";
	for (int j = 1; j <= 2; ++j) {
		std::cout << "\n\t\tDay " << j << " started";
		for (int h = 0; h < 24; ++h) {
			status = smart_home_process(h, status);
		}
	}
	
	return 0;
}