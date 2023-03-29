#include "Source.h"

int main() {

	cout << "\t\tTravel time\n\n";

	std::string timeDeparture = { "HH:MM" };
	std::string timeArrival = { "HH : MM" };
	int time_d{ 0 }, time_a{ 0 };

	cout << "Enter time of departure (HH:MM): "; cin >> timeDeparture;

	if (timeDeparture.length() != 5 || timeDeparture[2] != ':' || timeDeparture[0] < '0'
		|| timeDeparture[0] > '9' || timeDeparture[1] < '0' || timeDeparture[1] > '9'
		|| timeDeparture[3] < '0' || timeDeparture[3] > '9' || timeDeparture[4] < '0'
		|| timeDeparture[4] > '9') {
		cout << "Error's!";
	}
	else {
		int hour = 10 * (timeDeparture[0] - '0') + (timeDeparture[1] - '0');
		int minute = 10 * (timeDeparture[3] - '0') + (timeDeparture[4] - '0');

		if (hour > 23 || minute > 59) {
			cout << "Error!";
		}
		else {
			time_d = 60 * hour + minute;
		}
	}

	cout << "Enter time of arrival (HH:MM): "; cin >> timeArrival;

	if (timeArrival.length() != 5 || timeArrival[2] != ':' || timeArrival[0] < '0'
		|| timeArrival[0] > '9' || timeArrival[1] < '0' || timeArrival[1] > '9'
		|| timeArrival[3] < '0' || timeArrival[3] > '9' || timeArrival[4] < '0'
		|| timeArrival[4] > '9') {
		cout << "Error's!";
	}
	else {
		int hour = 10 * (timeArrival[0] - '0') + (timeArrival[1] - '0');
		int minute = 10 * (timeArrival[3] - '0') + (timeArrival[4] - '0');

		if (hour > 23 || minute > 59) {
			cout << "Error!";
		}
		else {
			time_a = 60 * hour + minute;
		}
	}

	int time{0}, h, m;
	if (time_a > time_d) {
		time = (time_a - time_d);
	}
	else if (time_d > time_a) {
		time = 1440 - (time_d - time_a);
	}

	h = time / 60;
	m = time % 60;

	cout << "Travel time: " << h << " hour's " << m << " minute's";

	return 0;
}