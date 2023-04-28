#include <iostream>
#include <cmath>

struct vector {
	float x;
	float y;
};


void add(const vector& const vec) {
	std::cout << "\nEnter second vector COORD (X:Y): ";
	vector vec_second;
	std::cin >> vec_second.x >> vec_second.y;
	std::cout << "Result vector: |" << vec.x + vec_second.x << " , " << vec.y + vec_second.y << "|\n";
}

void subtract(const vector& const vec) {
	std::cout << "\nEnter second vector COORD (X:Y): ";
	vector vec_second;
	std::cin>> vec_second.x >> vec_second.y;
	std::cout << "Result vector: |" << vec.x - vec_second.x << " , " << vec.y - vec_second.y << "|\n";
}

void scale(const vector& const vec) {
	std::cout << "Enter scalar: ";
	int num;
	std::cin >> num;
	std::cout << "Result vector: |" << vec.x * num << " , " << vec.y * num << "|\n";
}

void length(vector vec) {
	float res;
	res = sqrt(pow(vec.x, 2) + pow(vec.y, 2));
	std::cout << "Lenght vector: " << res<<std::endl;
}

void normalize(vector vec) {
	float l;
	l = sqrt(pow(vec.x, 2) + pow(vec.y, 2));
	std::cout << "Vector normalize: |" << vec.x / l << " , " << vec.y / l << "|\n";
}

int main() {
	std::cout << "\t\tMath's vector\n\n";

	vector vec;
	std::string action;
	std::cout << "Enter vector COORD (X:Y): ";
	std::cin >> vec.x >> vec.y;
	
	do {
		std::cout << "\nEnter action do you want do?\n - add - subtract - scale - length - normalize - "
			<<"\n - exit - \n";
		std::cin >> action;
		if (action == "add") {
			add(vec);
		}else if (action == "subtract") {
			subtract(vec);
		}else if (action == "scale") {
			scale(vec);
		}else if (action == "length") {
			length(vec);
		}else if (action == "normalize") {
			normalize(vec);
		}else {
			if (action != "exit") {
				std::cout << "\n\n\t\t\t!Incorrect input!\n\t\t\tTry again.";
			}
		}

	} while (action != "exit");

	return 0;
}