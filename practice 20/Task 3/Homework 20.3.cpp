#include <iostream>
#include <fstream>
#include <string>

void foldFish(const std::string& const fish,int& const co) {
	std::ofstream file_basket("basket.txt", std::ios::app);
	file_basket << fish << std::endl;
	file_basket.close();
	++co;
}

bool getFish(char fish[100],std::string& const fish_name) {
	std::ifstream file_river("river.txt");
	while (!file_river.eof()) {
		file_river.getline(fish, 100, '\n');
		std::string fish_get(fish);
		if (fish_get == fish_name) {
			return true;
		}
	}
	file_river.close();
	return false;
}

void fishingProcess() {
	char fish_get[100] = { 0, };
	int counter{ 0 };
	std::string fish;

	int check{ 0 };
	do {

		std::cout << "\nEnter fish type to get: ";
		std::cin >> fish;
		if (getFish(fish_get, fish)) {
			foldFish(fish, counter);
		}
		std::cout << "\nFor stopped fishing - Enter 1";
		std::cin >> check;
	} while (check != 1);

	std::cout << "You have: " << counter << " fish's!" << std::endl;
}

int main() {
	std::cout << "\t\tFishing simulator\n\n";

	fishingProcess();

	return 0;
}