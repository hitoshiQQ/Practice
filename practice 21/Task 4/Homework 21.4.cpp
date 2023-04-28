#include <iostream>
#include <time.h>
#include <fstream>

//============================================================
//                         Struct
struct position {
	int x = 0;
	int y = 0;
};

struct character {
	std::string nickname;
	int health;
	int armor;
	int damage;
	position pos;
};
//                         Struct
//============================================================

//============================================================
//                         All Function's
void processSaveGame(character& const player, character(&enemies)[5]);
void processLoadGame(character& const player, character(&enemies)[5], char(&table)[20][20]);

void playerCreateProcess(character& const player);
void processPlayerMove(character& const player, character(&enemies)[5], char(&table)[20][20]);

void processCharacterMove(character& const character, char(&table)[20][20], char type_sign, int& x, int& y);
void enemiesCreateProcess(character(&enemies)[5], char(&table)[20][20]);
bool checkEnemyHealth(character(&enemies)[5]);
void processEnemiesMove(character(&enemies)[5], character& player, char(&table)[20][20]);

void initializationGame(character& const player, character(&enemies)[5], char(&table)[20][20]);
void initializationGameMap(char(&table)[20][20]); 

void processBattle(character& attack, character& def, char(&table)[20][20]);
void processGameRound(character& player, character(&enemies)[5], char(&table)[20][20]);
//                         All Function's
//============================================================


//============================================================
//                        Save&Load
void processSaveGame(character& const player, character(&enemies)[5]) {
	std::ofstream file_gamesave("gamesave.txt");
	file_gamesave << player.nickname << std::endl;
	file_gamesave << player.health << std::endl;
	file_gamesave << player.armor << std::endl;
	file_gamesave << player.damage << std::endl;
	file_gamesave << player.pos.x << std::endl;
	file_gamesave << player.pos.y << std::endl;

	for (int j = 0; j < 5; ++j) {
		file_gamesave << enemies[j].nickname << std::endl;
		file_gamesave << enemies[j].health << std::endl;
		file_gamesave << enemies[j].armor << std::endl;
		file_gamesave << enemies[j].damage << std::endl;
		file_gamesave << enemies[j].pos.x << std::endl;
		file_gamesave << enemies[j].pos.y << std::endl;
	}
	file_gamesave.close();
}
void processLoadGame(character& const player, character(&enemies)[5], char(&table)[20][20]) {
	std::ifstream file_gamesave("gamesave.txt");
	if (!file_gamesave.is_open() || file_gamesave.peek() == EOF) {
		return initializationGame(player, enemies, table);
	}
	file_gamesave >> player.nickname;
	file_gamesave >> player.health;
	file_gamesave >> player.armor;
	file_gamesave >> player.damage;
	file_gamesave >> player.pos.x;
	file_gamesave >> player.pos.y;

	for (int j = 0; j < 5; ++j) {
		file_gamesave >> enemies[j].nickname;
		file_gamesave >> enemies[j].health;
		file_gamesave >> enemies[j].armor;
		file_gamesave >> enemies[j].damage;
		file_gamesave >> enemies[j].pos.x;
		file_gamesave >> enemies[j].pos.y;
	}
	file_gamesave.close();

	initializationGameMap(table);
	table[player.pos.x][player.pos.y] = 'P';
	for (int j = 0; j < 5; ++j) {
		if (enemies[j].health > 0) {
			table[enemies[j].pos.x][enemies[j].pos.y] = 'E';
		}
	}
}
//                        Save&Load
//============================================================


//============================================================
//                     Player & Character 
void playerCreateProcess(character& const player) {
	std::cout << "\n\nEnter name of your character: ";
	std::cin >> player.nickname;
	std::cout << "Enter health of your character: ";
	std::cin >> player.health;
	std::cout << "Enter armor of your character: ";
	std::cin >> player.armor;
	std::cout << "Enter damage of your character: ";
	std::cin >> player.damage;
	std::cout << "Enter COORD of your character (X:Y): ";
	std::cin >> player.pos.x >> player.pos.y;
}
void processPlayerMove(character& const player, character(&enemies)[5], char(&table)[20][20]) {
	int x = player.pos.x;
	int y = player.pos.y;
	bool fault = false;
	std::string move;
	std::cout << "Your move (W,A,S,D,save,load): ";
	std::cin >> move;
	if (move == "W") {
		y -= 1;
	}else if (move == "S") {
		y += 1;
	}else if (move == "A") {
		x -= 1;
	}else if (move == "D") {
		x += 1;
	}else if (move == "save" || move == "load") {
		(move == "save") ? processSaveGame(player, enemies) : processLoadGame(player, enemies, table);
		return processPlayerMove(player, enemies, table);
	}else {
		fault = true; 
	}

	if (x < 0 || y < 0) {
		fault = true;
		x = player.pos.x;
		y = player.pos.y;
	}

	while (fault) {
		fault = false;
		std::cout << "\nIncorrect step!Try again!";
		std::cin >> move;
		if (move == "W") {
			y -= 1;
		}
		else if (move == "S") {
			y += 1;
		}
		else if (move == "A") {
			x -= 1;
		}
		else if (move == "D") {
			x += 1;
		}
		else if (move == "save" || move == "load") {
			(move == "save") ? processSaveGame(player, enemies) : processLoadGame(player, enemies, table);
			return processPlayerMove(player, enemies, table);
		}
		else {
			fault = true;
		}
		if (x < 0 || y < 0) {
			fault = true;
			x = player.pos.x;
			y = player.pos.y;
		}
	}
	if (table[x][y] == 'E') {
		int enemy = 0;
		while (!(x == enemies[enemy].pos.x && y == enemies[enemy].pos.y)) {
			++enemy;
		}
		processBattle(player, enemies[enemy], table);
	}
	if (table[x][y] == '.') {
		processCharacterMove(player, table, 'P', x, y);
	}

	

		

}
void processCharacterMove(character& const character, char(&table)[20][20], char type_sign, int& x, int& y) {
	table[x][y] = type_sign;
	table[character.pos.x][character.pos.y] = '.';
	character.pos.x = x;
	character.pos.y = y;
}
//                     Player & Character 
//============================================================


//============================================================
//                          Enemies 
void enemiesCreateProcess(character(&enemies)[5], char(&table)[20][20]) {
	std::srand(std::time(NULL));
	for (int j = 0; j < 5; ++j) {
		enemies[j].nickname = "Bot";
		enemies[j].nickname += (j + 1);
		enemies[j].health = rand() % 101 + 50;
		enemies[j].armor = rand() % 51;
		enemies[j].damage = rand() % 16 + 15;
		enemies[j].pos.x = rand() % 40;
		enemies[j].pos.y = rand() % 40;
		while (table[enemies[j].pos.x][enemies[j].pos.y] != '.') {
			enemies[j].pos.x = rand() % 40;
			enemies[j].pos.y = rand() % 40;
		}
		table[enemies[j].pos.x][enemies[j].pos.y] = 'E';
	}
}
void processEnemiesMove(character(&enemies)[5], character& player, char(&table)[20][20]) {
	for (int j = 0; j < 5; ++j) {
		if (enemies[j].health > 0) {
			int x = enemies[j].pos.x;
			int y = enemies[j].pos.y;

			int move = rand() % 4;
			if (move == 0) {
				x -= 1;
			}else if (move == 1) {
				x += 1;
			}else if (move == 2) {
				y -= 1;
			}else if (move == 3) {
				y += 1;
			}
			
			if (x >= 0 && x < 20 && y >= 0 && y < 20) {
				if (table[x][y] == 'P') {
					processBattle(enemies[j], player, table);
				}
				if (table[x][y] == '.') {
					processCharacterMove(enemies[j], table, 'E', x, y);
				}
			}
		}
	}
}
bool checkEnemyHealth(character(&enemies)[5]) {
	if (enemies[0].health == 0 && enemies[1].health == 0 && enemies[2].health == 0 && enemies[3].health == 0
		&& enemies[4].health == 0) {
		return true;
	}
	return false;
}
//                          Enemies 
//============================================================


//============================================================
//                        Initialization Game&World
void initializationGame(character& const player, character(&enemies)[5], char(&table)[20][20]) {
	initializationGameMap(table);
	playerCreateProcess(player);
	table[player.pos.x][player.pos.y] = 'P';
	enemiesCreateProcess(enemies, table);
}
void initializationGameMap(char(&table)[20][20]) {
	for (int j = 0; j < 20; ++j) {
		for (int i = 0; i < 20; ++i) {
			table[j][i] = '.';
		}
	}
}
//                        Initialization Game&World
//============================================================


//============================================================
//                         Game Process
void processBattle(character& attack, character& def, char(&table)[20][20]) {
	int power = attack.damage;
	if (def.armor >= power) {
		def.armor -= power;
	}else {
		power -= def.armor;
		def.armor = 0;
		if (def.health <= power) {
			def.health = 0;
			table[def.pos.x][def.pos.y] = '.';
		}else {
			def.health -= power;
		}
	}
}

void processGameRound(character& player, character(&enemies)[5], char(&table)[20][20]) {
	for (int j = 0; j < 20; ++j) {
		for (int i = 0; i < 20; ++i) {
			std::cout << table[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	processPlayerMove(player, enemies, table);
	processEnemiesMove(enemies, player, table);
}
//                         Game Process
//============================================================


int main() {
	std::cout << "\t\tTurn-based role-playing game\n\n";

	character player;
	character enemies[5];
	char table[20][20];
	std::cout << "Load game? (y/n): ";
	char act;
	std::cin >> act;
	if (act == 'y') {
		processLoadGame(player, enemies, table);
	}else {
		initializationGame(player, enemies, table);
	}

	while (player.health > 0 && !checkEnemyHealth(enemies)) {
		processGameRound(player, enemies, table);
	}

	if (player.health == 0) {
		std::cout << "\n\n\t\t\tYou are LOSE!!!\n";
	}else {
		std::cout<< "\n\n\t\t\tYou are WIN!!!\n";
	}

	return 0;
}