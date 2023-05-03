#include <iostream>

#define WEEKDAY_1 "Monday"
#define WEEKDAY_2 "Tuesday"
#define WEEKDAY_3 "Wednesday"
#define WEEKDAY_4 "Thursday"
#define WEEKDAY_5 "Friday"
#define WEEKDAY_6 "Saturday"
#define WEEKDAY_7 "Sunday"
#define SHOW_WEEKDAY(func,day) func ## _ ## day

int main() {
	int day;
	do {
		std::cout << "\nEnter the day of the week: ";
		std::cin >> day;
		switch (day) {
		  case 1: {
			  std::cout << SHOW_WEEKDAY(WEEKDAY, 1) << std::endl;
			  break;
		  }
		  case 2: {
			  std::cout << SHOW_WEEKDAY(WEEKDAY, 2) << std::endl;
			  break;
		  }
		  case 3: {
			  std::cout << SHOW_WEEKDAY(WEEKDAY, 3) << std::endl;
			  break;
		  }
		  case 4: {
			  std::cout << SHOW_WEEKDAY(WEEKDAY, 4) << std::endl;
			  break;
		  }
		  case 5: {
			  std::cout << SHOW_WEEKDAY(WEEKDAY, 5) << std::endl;
			  break;
		  }
		  case 6: {
			  std::cout << SHOW_WEEKDAY(WEEKDAY, 6) << std::endl;
			  break;
		  }
		  case 7: {
			  std::cout << SHOW_WEEKDAY(WEEKDAY, 7) << std::endl;
			  break;
		  }
		}
	} while (day > 0 && day <= 7);

	return 0;
}