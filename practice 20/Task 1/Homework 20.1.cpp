#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void checkName(std::string& const name) {
	for (int j = 0; j < name.length(); ++j) {
		if ((name[j] < 'A' || name[j]>'Z') && (name[j]<'a' || name[j] > 'z')) {
			std::cout << "\nIncorrect NAME input!.\nTry again: ";
			std::cin >> name;
			checkName(name);
		}
	}
}

void checkSurname(std::string& const surname) {
	for (int j = 0; j < surname.length(); ++j) {
		if ((surname[j] < 'A' || surname[j]>'Z')&& (surname[j] < 'a' || surname[j] > 'z')) {
			std::cout << "\nIncorrect SURNAME input!.\nTry again: ";
			std::cin >> surname;
			checkSurname(surname);
		}
	}
}

void checkPayment(std::string& const payment) {
	int pay = std::stoi(payment);
	if (pay <= 0) {
		std::cout<< "\nIncorrect MONEY input!.\nTry again: ";
		std::cin >> payment;
		checkPayment(payment);
	}
}

void enterData(std::string& const name, std::string& const surname,
	std::string& const date, std::string& const payment) {
	std::cout << "\nData entry format : \"NAME SURNAME DD.MM.YY PAYMENT\" :";
	std::cin >> name >> surname >> date >> payment;
}

void checkDate(std::string& const date) {
	if (date.length() != 8) {
		std::cout<< "\nIncorrect DATE input!.\nTry again : ";
		std::cin >> date;
		checkDate(date);
	}
	int D = std::stoi(date.substr(0, 2));
    int M = std::stoi(date.substr(3, 2));
    int Y = std::stoi(date.substr(6, 2));

	if(!(D > 0 && (
		(D <= 31 && (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12)) ||
		(D <= 30 && (M == 4 || M == 6 || M == 9 || M == 11)) ||
		(M == 2 && ((D <= 29 && (Y % 4 == 0 && Y % 100 != 0)) ||
			(D <= 28 && ((Y % 4 == 0 && Y % 100 == 0) || Y % 4 != 0))))))){
		std::cout << "\nIncorrect DATE input!.\nTry again : ";
		std::cin >> date;
		checkDate(date);
	}
}

void checkData(std::string& const name, std::string& const surname,
	std::string& const date, std::string& const payment) {
	checkName(name);
	checkSurname(surname);
	checkDate(date);
	checkPayment(payment);
}

void writeFile(const std::string& const name, const std::string& const surname,
	const std::string& const date,const std::string& const payment) {
	std::ofstream file ("statement.txt", std::ios::app);
	file.setf(std::ios::fixed);
	file << name << "  " << surname << "  "  << date << "  " << payment << std::endl;
	file.close();
}

int main() {
	std::cout << "\t\tStatement of account entry\n\n";
	
	int check;
	do {
		std::string first_name, sur_name, date, payment;
		enterData(first_name, sur_name, date, payment);
		checkData(first_name, sur_name, date, payment);
		writeFile(first_name, sur_name, date, payment);
		std::cout << "\n\nDo you want to end the session? Enter - 1";
		std::cin >> check;
	} while (check!=1);
	
	
	return 0;
}