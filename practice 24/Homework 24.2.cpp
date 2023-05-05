#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>

struct Person
{
	std::string name = "unknown";
	std::tm date;
};

time_t t = time(nullptr);
tm local = *localtime(&t);

std::vector<Person> BD;
std::vector<Person> todayBD;
std::vector<Person> nearBD;
 
void checkName(std::string& const name) {
	for (int j = 0; j < name.length(); ++j) {
		if ((name[j] < 'A' || name[j]>'Z') && (name[j] < 'a' || name[j] > 'z')) {
			std::cout << "\nIncorrect NAME input!.\nTry again: ";
			std::cin >> name;
			checkName(name);
		}
	}
}

void addPersonBirthday(std::string& const name) {
	Person curr_person;
	curr_person.name = name;
	curr_person.date = local;
	std::cout << "\nEnter birthday [YYYY/MM/DD]: ";
	std::cin >> std::get_time(&curr_person.date, "%Y/%m/%d");
	BD.push_back(curr_person);
}

void enterName() {
	std::string name;
	std::cout << "\nEnter the name of person in reminder [end - for stop]: ";
	std::cin >> name;
	checkName(name);

	while (name != "end") {
		addPersonBirthday(name);
		std::cout << "\nEnter the name of person in reminder [end - for stop]: ";
		std::cin >> name;
		checkName(name);
	}
}

int daysAmount(tm& date) {
	int allDays = 0;
	int d = date.tm_mday;
	int m = date.tm_mon;
	int y = date.tm_year;

	for (int j = 0; j < m; ++j) {
		if (j == 3 || j == 5 || j == 8 || j == 10) {
			allDays += 30;
		}else if(j == 2) {
			if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)) {
				allDays += 29;
			}else {
				allDays += 28;
			}
		
		}else {
			allDays += 31;
		}
	}
	allDays += d;

	return allDays;
}

bool checkNearestBD(Person& bday, tm& curr_t, tm& nearest_t) {
	if (daysAmount(nearest_t) < daysAmount(curr_t)) {
		if (daysAmount(bday.date) < daysAmount(nearest_t) || (daysAmount(bday.date) > daysAmount(curr_t))) {
			return true;
		}
	}else {
		if (daysAmount(bday.date) > daysAmount(curr_t)
			&& daysAmount(bday.date) < daysAmount(nearest_t)) {
			return true;
		}
		return false;
	}
}

void processNearestBDays() {
	std::tm curr_t = local;
	std::tm nearBD_t;
	for (int j = 0; j < BD.size(); ++j)
	{
		if (daysAmount(BD[j].date) == daysAmount(curr_t))
			todayBD.push_back(BD[j]);
		else
		{
			if (nearBD.empty())
			{
				nearBD.push_back(BD[j]);
				nearBD_t = BD[j].date;
			}
			else
			{
				if (daysAmount(BD[j].date) ==
					daysAmount(nearBD_t))
				{
					nearBD.push_back(BD[j]);
				}
				else
				{
					if (checkNearestBD(BD[j], curr_t, nearBD_t))
					{
						nearBD.clear();
						nearBD.push_back(BD[j]);
						nearBD_t = BD[j].date;
					}
				}
			}
		}
	}
}


void printBD() {
	if (!todayBD.empty())
	{
		std::cout << std::endl << "Today ["<< std::put_time(&local, "%m/%d") << "] | Birth Days:" << std::endl;
		for (auto person : todayBD)
			std::cout << person.name << std::endl;
	}

	if (!nearBD.empty())
	{
		if (nearBD.size() > 1)
		{
			std::cout << std::endl << "Nearest Birth Days:" << std::endl;
			for (auto person : nearBD)
			{
				std::cout << person.name << " || "<< std::put_time(&person.date, "%m/%d") << std::endl;
			}
		}
		else
		{
			std::cout << std::endl << "Nearest Birth Day:" << std::endl;
			std::cout << nearBD[0].name << ": "<< std::put_time(&nearBD[0].date, "%m/%d");
			std::cout << std::endl;
		}
	}
}

int main() {
	std::cout << "\t\tBirth Day's Reminder\n\n";
	
	enterName();
	processNearestBDays();
	printBD();

	return 0;
}