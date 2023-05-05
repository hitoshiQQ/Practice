#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <iomanip>
#include <windows.h>

int main() {
	std::cout << "\t\tTimer\n\n";

	time_t curr_t = time(nullptr);
	tm set_t = *localtime(&curr_t);

	std::cout << "\t\t|TIMER SETTING|\nEnter the interval[MM:SS]: ";
	do {
		std::cin >> std::get_time(&set_t, "%M:%S");
		if (std::cin.good()) {
			break;

			std::cerr << "\nIncorrect input.Try again!";
			std::cin.clear();
		}
	} while (true);

	curr_t = time(nullptr);
	tm _curr_t = *localtime(&curr_t);
	set_t.tm_min += _curr_t.tm_min;
	set_t.tm_sec += _curr_t.tm_sec;
	time_t end = mktime(&set_t);

	while (curr_t < end) {
		time_t time_left = end - curr_t;
		set_t = *localtime(&time_left);
		std::cout << std::put_time(&set_t, "%M:%S") << std::endl;
		Sleep(990);
		curr_t = time(nullptr);
	}

	std::cout << "\n\t\t\t!!DING! DING! DING!!\n\n";

	return 0;
}