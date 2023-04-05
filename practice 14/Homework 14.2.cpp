#include "Source.h"
#include <vector>

bool is_win(std::vector<std::vector<char>>::iterator table, char symbol) {
	for (int j = 0; j < 3; ++j) {
		if (table[j][0] == symbol && table[j][1] == symbol && table[j][2] == symbol)
			return true;
		if (table[0][j] == symbol && table[1][j] == symbol && table[2][j] == symbol)
			return true;
	}
	if (table[0][2] == symbol && table[1][1] == symbol && table[2][0] == symbol)
		return true;
	if (table[0][0] == symbol && table[1][1] == symbol && table[2][2] == symbol)
		return true;

	return false;
}

void init_table(std::vector<std::vector<char>>::iterator table) {
	
	std::cout << "-----------\n";
	for (int j = 0; j < 3; ++j) {
		std::cout << " | ";

		for (int i = 0; i < 3; ++i) {
			std::cout << table[j][i] << " ";		
		}
		std::cout << "|\n";
	}
	std::cout << "-----------\n";
}

bool move_table(std::vector<std::vector<char>>::iterator table, int x, int y, char symbol) {
	if (x < 0 || y < 0 || x>2 || y>2) {
		std::cout << "\n\t\tIncorrect input! Try again!\n";
		return true;
	}
	if (table[x][y] != ' ') {
		std::cout << "\n\t\tThere is already a symbol here\n";
	}
	table[x][y] = symbol;
	return false;
}

bool control_check_move(std::vector<std::vector<char>>::iterator table) {
	for (int j = 0; j < 3; ++j) {
		for (int i = 0; i < 3; ++i) {
			if (table[j][i] == ' ')
				return false;
		}
	}
	return true;
}

int control_check_table(std::vector<std::vector<char>>::iterator table) {
	if (control_check_move(table))
		return 0;
	if (is_win(table, 'x'))
		return 1;
	if (is_win(table, 'o'))
		return 2;
	return -1;
}

int main() {

	cout << "\t\tTic-Tac-Toe\n\n";
	
	int x, y, game;
	std::vector<std::vector<char>> table{{' ',' ',' '},
								         {' ',' ',' '},
								         {' ',' ',' '}};
	auto iter = table.begin();

	do {
		init_table(iter);
		do {
			std::cout << "\n\t\t\tFirst player - You turn!\n";
			cin >> x >> y;
		} while (move_table(iter, --x, --y, 'x'));
		game = control_check_table(iter);
		if (game == 1 || game == 0)
			break;

		init_table(iter);
		do {
			std::cout << "\n\t\t\tSecond player - You turn!\n";
			cin >> x >> y;
		} while (move_table(iter, --x, --y, 'o'));
		game = control_check_table(iter);

	} while (game == -1);


	if (game == 1) {
		std::cout << "\n\t\t 1st player is a WIN!!!\n";
	}
	else if (game == 2) {
		std::cout << "\n\t\t 2nd player is a WIN!!!";
	}
	else {
		std::cout << "\n\t\tDraw\n";
	}


	return 0;
}