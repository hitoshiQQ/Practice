#include "Source.h"
#include <cassert>

void quicksort(float* l, float* r) {
	if (r - l <= 1) return;
	float z = *(l + (r - l) / 2);
	float* ll = l, * rr = r - 1;
	while (ll <= rr) {
		while (*ll < z) ll++;
		while (*rr > z) rr--;
		if (ll <= rr) {
			std::swap(*ll, *rr);
			ll++;
			rr--;
		}
	}
	if (l < rr) quicksort(l, rr + 1);
	if (ll < r) quicksort(ll, r);
}

void print(float* numbers,const int size) {
	for (int j = 0; j < size; ++j) {
		cout << numbers[j] << endl;
	}
}

int main() {

	cout << "\t\tSorting\n\n";

	const int size{ 15 };
	float numbers[size]{};
	for (int j = 0; j < size; ++j) {
		cout << "Enter number's: ";
		cin >> numbers[j];
	}

	float* l = std::begin(numbers);
	float* r = std::end(numbers);
	quicksort(l, r);

	print(numbers, size);

	



}