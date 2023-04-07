#include "Source.h"

void print_bubble(bool bubble[][12]) {
	for (int j = 0; j < 12; ++j) {
		for (int i = 0; i < 12; ++i) {
			if (bubble[j][i]) {
				std::cout << 'o';
			}else {
				std::cout << 'x';
			}
		}
		std::cout << std::endl;
	}
}

bool control_check_pos(int& x_posStart, int& y_posStart, int& x_posEnd, int& y_posEnd) {
	if (((x_posStart < 0) || (x_posStart > 11)) || ((y_posStart < 0) || (y_posStart > 10))
		 || ((x_posEnd < 0) || (x_posEnd > 11)) || ((y_posEnd < 0) || (y_posEnd > 11))) {
		return false;
	}
	return true;
}

void bursting_bubble(bool bubble[][12], int& co, int& x_posStart
	, int& y_posStart, int& x_posEnd, int& y_posEnd) {

	for (int j = x_posStart; j <= x_posEnd; ++j) {
		for (int i = y_posStart; i <= y_posEnd; ++i) {
			if (bubble[j][i]) {
				bubble[j][i] = false;
				co++;
				std::cout << "\n\t\t!POP!\n";
			}
		}
	}
}


int main() {

	std::cout << "\t\tBubble\n\n";

	bool bubble[12][12];
	
	for (int j = 0; j < 12; ++j) {
		for (int i = 0; i < 12; ++i) {
			bubble[j][i] = true;
		}
	}

	int co{0}, x_posStart, y_posStart, x_posEnd, y_posEnd;
	while (co < 144) {
		print_bubble(bubble);
		std::cout << "Enter start position to pop: ";
		std::cin >> x_posStart >> y_posStart;
		std::cout << "Enter end position to pop: ";
		std::cin >> x_posEnd >> y_posEnd;

		if (control_check_pos(x_posStart, y_posStart, x_posEnd, y_posEnd)) {
			bursting_bubble(bubble, co, x_posStart, y_posStart, x_posEnd, y_posEnd);
		}else {
			std::cout << "\n\t\tIncorrect position!\n";
		}
	}

	std::cout << "\nAll bubble are burst!\n";

	return 0;
}