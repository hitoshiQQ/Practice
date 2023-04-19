#include "Source.h"
#include <vector>
#include <sstream>

enum notes {
	DO = 1U << 0,  RE = 1U << 1,
	MI = 1U << 2,  FA = 1U << 3,
	SOL = 1U << 4, LA = 1U << 5,
	SI = 1U << 6
};

int melody[12];
std::stringstream istream;

std::string note_to_string() {
	std::string res = "";
	for (int j = 0; j < 12; ++j) {
		if (melody[j] & DO) {
			res += " DO";
		}
		if (melody[j] & RE) {
			res += " RE";
		}
		if (melody[j] & MI) {
			res += " MI";
		}
		if (melody[j] & FA) {
			res += " FA";
		}
		if (melody[j] & SOL) {
			res += " SOL";
		}
		if (melody[j] & LA) {
			res += " LA";
		}
		if (melody[j] & SI) {
			res += " SI";
		}
	}
	return res;
}

bool is_correct_notes(std::string note) {
	for (int j = 0; j < note.size(); ++j) {
		if (note[j] > '7' || note[j] < '1') {
			return false;
		}
		note[j] -= 1;
	}
	return true;
}

int enter_accord() {
	std::string enter_note = "";
	int res{ 0 };
	bool is_not_correct = true;
	do {
		std::cout << "Enter note's (1 - 7): ";
		std::cin >> enter_note;
		is_not_correct = !is_correct_notes(enter_note);
		if (is_not_correct) {
			std::cout << "Try again!\n";
		}

	} while (is_not_correct);

	for (int j = 0; j < enter_note.size(); ++j) {
		res |= 1 << (enter_note[j] - 49);
	}
	return res;
}

void enter_melody() {
	for (int j = 0; j < 12; ++j) {
		melody[j] = enter_accord();
	}
}

int main() {
	std::cout << "\t\tMechanical Piano\n\n";
	
	enter_melody();
	std::cout << note_to_string();
	
	return 0;
}