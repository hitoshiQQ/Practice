#include "Source.h"

int main() {

	cout << "\t\tLong tangible number\n\n";

	std::string num;

	cout << "Enter the number: ";
	cin >> num;
	
	bool check = true;
	int dat{ 0 }, minus{ 0 }, nums{ 0 };

	for (int j = 0; j < num.length(); ++j) {


		if (num[j] == '.') {
			++dat;
		}	
		if (num[j] == '-') {
			++minus;
		}
		if (num[j] <= '9' && num[j] >= '0') {
			++nums;
		}	
		if ( (num[j] < '0' || num[j]  > '9') && dat!=1 && minus!=1) {
			check = false;
			break;
		}
	}

	if (nums==0) {
		cout << "No!";
	}
	else if (check) {
		cout << "Yes!";
	}else {
		cout << "No!";
	}
		
	return 0;
}