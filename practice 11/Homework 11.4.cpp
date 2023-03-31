#include "Source.h"


char element(std::string location, int x, int y) {
	return location[x * 3 + y];
}

std::string get_column(std::string location, int y) {
	std::string column = "   ";
	for (int j = 0; j < 3; ++j) {
		column[j] = element(location, j, y);
	}
	return column;
}

std::string get_diagonal(std::string location, int q) {
	std::string diagonal = "   ";
	if (q == 0) {
		for (int j = 0; j < 3; ++j) {
			diagonal[j] = element(location, j, j);
		}
	}
	else {
		for (int j = 0; j < 3; ++j) {
			diagonal[j] = element(location, j, 2-j);
		}
	}
	return diagonal;
}

int countElement(std::string location, char ch) {
	int count{ 0 };
	for (int j = 0; j < 9; ++j) {
		if (location[j] == ch) {
			count++;
		}
	}
	return count;
}

bool error(std::string location) {
	if (location.length() != 9)
		return true;
	std::string check = "xo.";

	for (int j = 0; j < 9; ++j) {
		if (check.find(location[j]) == std::string::npos)
			return true;
	}
	if (countElement(location, 'x') != countElement(location, 'o')
		&& countElement(location, 'x') != countElement(location, 'o') + 1) {
		return true;
	}
	return false;
}

void win_rows(std::string top, std::string mid, std::string low,int&xW , int&oW) {
	if (top == "xxx") {
		xW++;
	}else if (top == "ooo") {
		oW++;
	}
	if (mid == "xxx") {
		xW++;
	}
	else if ( mid == "ooo") {
		oW++;
	}
	if (low == "xxx") {
		xW++;
	}
	else if (low == "ooo") {
		oW++;
	}
}

void win_columns(std::string  location, int& xW, int& oW) {
	for (int j = 0; j < 3; ++j) {
		if (get_column(location, j) == "xxx") {
			xW++;
		}else if (get_column(location, j) == "ooo") {
			oW++;
		}
	}
}

void win_diagonal(std::string  location, int& xW, int& oW) {
	if (get_diagonal(location, 0) == "xxx") {
		xW++;
	}else if (get_diagonal(location, 0) == "ooo") {
		oW++;
	}

	if (get_diagonal(location, 1) == "xxx") {
		xW++;
	}else if (get_diagonal(location, 1) == "ooo") {
		oW++;
	}

}


std::string is_winner(std::string top, std::string mid, std::string low) {
	std::string location = top + mid + low;
	if (error(location)) {
		return "\n\t\tIncorrect\n";
	}
	int win_X{0}, win_O{0};
	win_rows(top, mid, low, win_X, win_O);
	win_columns(location, win_X, win_O);
	win_diagonal(location, win_X, win_O);

	if (win_X + win_O == 0) {
		return "\n\t\tNobody\n";
	}
		
	if (win_O == 1) {
		if (countElement(location, 'x') == countElement(location, 'o')) {
			return"\n\t\tVanya - Win!!!\n";
		}else {
			return "\n\t\tIncorrect\n";
		}
	}else {
		if (countElement(location, 'x') == countElement(location, 'o') + 1) {
			return "\n\t\tPetya - Win!!!\n";
		}else {
			return "\n\t\tIncorrect\n";
		}
	}
}


int main() {
	cout << "\t\tEvaluation of the results of the game of tic-tac-toe\n\n";

	std::string topLine, midLine, lowLine;
	cout << "Enter the line's: \n";
	cin >> topLine >> midLine >> lowLine;
	cout << is_winner(topLine, midLine, lowLine);

	return 0;
}