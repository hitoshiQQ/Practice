#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

struct Statement {

	std::string name    = "Unkown";
	std::string surname = "Unkown";
	std::string date    = "XX.XX.XXXX";
	int payment         = 0;
};


void checkDate(std::string& const date) {
	if (date.length() != 10) {
		std::cout << "\nIncorrect DATE input!.\nTry again : ";
		std::cin >> date;
		checkDate(date);
	}
	int D = std::stoi(date.substr(0, 2));
	int M = std::stoi(date.substr(3, 2));
	int Y = std::stoi(date.substr(6, 4));

	if (!(D > 0 && (
		(D <= 31 && (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12)) ||
		(D <= 30 && (M == 4 || M == 6 || M == 9 || M == 11)) ||
		(M == 2 && ((D <= 29 && (Y % 4 == 0 && Y % 100 != 0)) ||
			(D <= 28 && ((Y % 4 == 0 && Y % 100 == 0) || Y % 4 != 0))))))) {
		std::cout << "\nIncorrect DATE input!.\nTry again : ";
		std::cin >> date;
		checkDate(date);
	}
}

void checkName(std::string& const name) {
	for (int j = 0; j < name.length(); ++j) {
		if ((name[j] < 'A' || name[j]>'Z') && (name[j] < 'a' || name[j] > 'z')) {
			std::cout << "\nIncorrect NAME input!.\nTry again: ";
			std::cin >> name;
			checkName(name);
		}
	}
}

void checkSurname(std::string& const surname) {
	for (int j = 0; j < surname.length(); ++j) {
		if ((surname[j] < 'A' || surname[j]>'Z') && (surname[j] < 'a' || surname[j] > 'z')) {
			std::cout << "\nIncorrect SURNAME input!.\nTry again: ";
			std::cin >> surname;
			checkSurname(surname);
		}
	}
}

void checkPayment(int& const payment) {
	if (payment <= 0) {
		std::cout << "\nIncorrect MONEY input!.\nTry again: ";
		std::cin >> payment;
		checkPayment(payment);
	}
}

void checkData(Statement& person) {
	checkName(person.name);
	checkSurname(person.surname);
	checkDate(person.date);
	checkPayment(person.payment);
}

std::string getCommand() {
	std::string command;
	std::cout << "\nEnter the desired action:\n- Add - - List - - Quit-\n";
	std::cin >> command;
	for (char& j : command) {
		j = (char)tolower(j);
	}
	return command;
}

bool writeFile(Statement& person, const std::string& const filename) {
	std::ofstream file("statement.txt", std::ios::app);
	if (file.is_open()) {
		checkData(person);
		file << person.name << " ";
		file << person.surname << " ";
		file << person.date << " ";
		file << person.payment << std::endl;
		file.close();
		return true;
	}
	std::cerr << "\n\t\t!File path - Error!\n";
	return false;
}

void printStatement(Statement& person) {
	std::cout << person.name << " " << person.surname << "  "
		<< person.date << " " << person.payment << std::endl;
}

bool printFile(Statement& person, const std::string& const filename) {
	std::ifstream file("statement.txt", std::ios::in);
	if (file.is_open()) {
		std::cout << std::endl;
		while (!file.eof()) {
			if (file >> person.name) {
				file >> person.surname;
				file >> person.date;
				file >> person.payment;
				printStatement(person);
			}
		}
		file.close();
		return true;
	}
	std::cerr << "\n\t\t!File path - Error!\n";
	return false;
}

int main() {
	std::cout << "\t\tStatement of account entry\n\n";

	std::string command;
	Statement person;

	do {
		command = getCommand();
		if (command == "add") {
			std::cout << "\nData entry format : \"NAME SURNAME DD.MM.YYYY PAYMENT\" :";
			std::cin >> person.name >> person.surname >> person.date >> person.payment;
			writeFile(person, "statement.txt");
		}
		else if (command == "list") {
			printFile(person, "statement.txt");
		}

	} while (command != "quit");

	return 0;
}