#include "Source.h"
#include <vector>



void enter_melody(std::vector<std::string>&const str) {
	std::cout << "Enter the melody: ";
	for (int j = 0; j < 12; ++j) {
		std::cin >> str[j];
	}
}

void play_melody(const std::vector<std::string>& const melody,const std::vector<std::string>& const note) {
	std::cout << "\nPlay the melody!\n";

	for (int j = 0; j < 12; ++j) {
		std::string temp = melody[j];
		for (int i = 0; i < temp.size(); ++i) {
			std::cout << note[((int)temp[i] - 48)-1];
		}
		std::cout << std::endl;
	}
}

int main() {
	std::cout << "\t\tMechanical Piano\n\n";

	std::vector<std::string> notes { "DO","RE","MI","FA","SOL","LA","SI" };
	std::vector<std::string> melody(12);

	enter_melody(melody);
	play_melody(melody, notes);

	return 0;
}