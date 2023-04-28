#include <iostream>
#include <fstream>
#include <vector>


enum building_variety {
	HOUSE,
	GARAGE,
	BATHS,
	BARN,
	UNKOWN
};

enum room_variety {
	BEDROOM,
	KITCHEN,
	BATHROOM,
	CHILDREN_ROOM,
	LIVING_ROOM,
	UNKOWN_ROOM
};

struct Room {
	room_variety type;
	int square = 0;
};

struct Curr_floor {
	int height;
	int rooms_amount = 1;
	std::vector<Room> rooms;
};

struct Building {
	building_variety type;
	int square;
	bool heater;
	int floors_amount = 1;
	std::vector<Curr_floor> floors;
};

struct Territory {
	int num;
	int square;
	int building_num;
	std::vector<Building> buildings;
};

building_variety buildingTypeDetection(const std::string& const type) {
	if (type == "house") {
		return HOUSE;
	}else if (type == "garage") {
		return GARAGE;
	}else if (type == "baths") {
		return BATHS;
	}else if (type == "barn") {
		return BARN;
	}else {
		return UNKOWN;
	}
}

std::string reverseBuildingTypeDetection(const building_variety& const type) {
	if (type == HOUSE) {
		return "house";
	}else if (type == GARAGE) {
		return "garage";
	}else if (type == BATHS) {
		return "baths";
	}else if (type == BARN) {
		return "barn";
	}else {
		return "UNKOWN BUILDING'S";
	}
}


room_variety roomTypeDetection(const std::string& const type) {
	if (type == "bedroom") {
		return BEDROOM;
	}else if (type == "kitchen") {
		return KITCHEN;
	}else if (type == "bathroom") {
		return BATHROOM;
	}else if (type == "childrenroom") {
		return CHILDREN_ROOM;
	}else if (type == "livingroom") {
		return LIVING_ROOM;
	}else {
		return UNKOWN_ROOM;
	}
}

std::string reverseRoomTypeDetection(const room_variety& const type) {
	if (type == BEDROOM) {
		return "bedroom";
	}else if (type == KITCHEN) {
		return "kitchen";
	}else if (type == BATHROOM) {
		return "bathroom";
	}else if (type == CHILDREN_ROOM) {
		return "childrenroom";
	}else if (type == LIVING_ROOM) {
		return "livingroom";
	}else {
		return "UNKOWN ROOM'S";
	}
}

void RoomCreateProcess(Room& const room,int& const amt) {
	std::cout << "\nRoom type: " << amt + 1;
	std::cout << "\tEnter type of room: ";
	std::string room_type_tmp;
	std::cin >> room_type_tmp;
	room.type = roomTypeDetection(room_type_tmp);
	std::cout << "\t\tEnter the square of room: ";
	std::cin >> room.square;
}

void FloorCreateProcess(Curr_floor& const floor, const int& const amt) {
	std::cout << "\nEnter "<<amt+1<<" floor height : ";
	std::cin >> floor.height;
	std::cout << "\tEnter the amount  of room's: ";
	std::cin >> floor.rooms_amount;
	for (int j = 0; j < floor.rooms_amount; ++j) {
		Room room_tmp;
		RoomCreateProcess(room_tmp, j);
		floor.rooms.push_back(room_tmp);
	}
}

void BuildingCreateProcess(Building& const building,int& const amt) {
	std::cout << "\n\nEnter the " << amt + 1 << " building square: ";
	std::cin >> building.square;
	std::cout << "\tEnter the " << amt + 1 << " building type: ";
	std::string building_tmp;
	std::cin >> building_tmp;
	building.type = buildingTypeDetection(building_tmp);
	if (building.type == HOUSE || building.type == BATHS) {
		std::cout << "\t\tHave a heater? (Yes = 1 || No = 0): ";
		std::cin >> building.heater;
		if (building.type == HOUSE) {
			std::cout << "\t\t\tEnter numbers of floor's in house: ";
			std::cin >> building.floors_amount;
			for (int j = 0; j < building.floors_amount; ++j) {
				Curr_floor floor_tmp;
				FloorCreateProcess(floor_tmp, j);
				building.floors.push_back(floor_tmp);
			}
		}
	}
}

void TerritoryCreateProcess(Territory& const territory) {
	std::cout << "\nEnter the territory number's: ";
	std::cin >> territory.num;
	territory.square = 1000;
	std::cout << "\tEnter amount building's: ";
	std::cin >> territory.building_num;
	for (int j = 0; j < territory.building_num; ++j) {
		Building building_tmp;
		BuildingCreateProcess(building_tmp, j);
		territory.buildings.push_back(building_tmp);
	}
}

void writeFile(std::vector<Territory>& village, int amt) {
	std::ofstream file_village("village.txt", std::ios::app);
	for (int j = 0; j < amt; ++j) {
		file_village << "\nTerritory ¹:" << village[j].num << " || square: " << village[j].square
			<< " || Amount of building's: " << village[j].building_num << std::endl;
		for (int i = 0; i < village[j].building_num; ++i) {
			file_village << "Building ¹" << j+1+i << " is " << reverseBuildingTypeDetection(village[j].buildings[i].type)
				<< " || square: " << village[j].buildings[i].square << std::endl;
			if (village[j].buildings[i].type == HOUSE) {
				file_village << "Number floor's: " << village[j].buildings[i].floors_amount << std::endl;
				for (int q = 0; q < village[j].buildings[i].floors_amount; ++q) {
					file_village << "Floor " << q + 1 << " || height: " << village[j].buildings[i].floors[q].height
						<< " || Number room's: " << village[j].buildings[i].floors[q].rooms_amount << std::endl;
					for (int z = 0; z < village[j].buildings[i].floors[q].rooms_amount; ++z) {
						file_village << "Room ¹" << z + 1 << " type: " 
							<< reverseRoomTypeDetection(village[j].buildings[i].floors[q].rooms[z].type)
							<< " || square: " << village[j].buildings[i].floors[q].rooms[z].square
							<< std::endl;
					}
				}
			}
		}
	}
	file_village.close();
}

int main() {
	std::cout << "\t\tData for Village\n\n";

	bool fill = true;
	int co = 0;
	std::vector<Territory> village;
	while (fill) {
		Territory territory_curr;
		TerritoryCreateProcess(territory_curr);
		village.push_back(territory_curr);
		++co;
		std::cout << "\nDo you want to continue? (Yes = 1 || No = 0): ";
		std::cin >> fill;
	}
	writeFile(village, co);

	return 0;
}