#include "Source.h"

int search_repeat_num(int num[]) {
	int min = num[0], sumAll{ 0 };
	for (int j = 0; j < 15; ++j) {
		if (num[j] < min) {
			min = num[j];
		}
		sumAll += num[j];
	}
    int sum{ 0 };
	for (int j = 0; j < 14; ++j) {
		sum += min;
		min++;
	}

	return sumAll - sum;
}

int main() {

	cout << "\t\tSeries of numbers\n\n";

	int numbers[15] = { 114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118 };
	cout<<search_repeat_num(numbers);
	
	return 0;
}