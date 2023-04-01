#include "Source.h"
#include <cassert>

inline float travelTime(float distance, float speed) {
	assert(speed > 0);
	return distance / speed;
}

int main() {

	cout << "\t\tUsing assert\n\n";

	float speed, distance;
	cout << "Enter speed: "; cin >> speed;
	cout << "Enter distance: "; cin >> distance;

	cout << "Travel time: " << travelTime(distance, speed);
	
	return 0;
}
