#include "Source.h"

int main()
{
	cout << "\t\tHerringbone\n\n";

	int height;
	cout << "Enter the height of the herringbone: "; cin >> height;


	for (int j = 0; j < height; ++j) {
		for (int i = 1; i < height-j; ++i) {
			cout << " ";
		}
		for (int i = height - 2 * j; i <= height; ++i)
		{
			cout << "#";
		}
		cout << endl;
	}

	return 0;
}