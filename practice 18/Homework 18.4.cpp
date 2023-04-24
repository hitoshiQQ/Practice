#include <iostream>

void evenDigits(const long long& const num, int& const ans) {
	if (num != 0) {
		if ((num % 10) % 2 == 0) {
			++ans;
		}
		evenDigits(num /10, ans);
	}		
}

int main() {
	std::cout << "\t\tTask 4\n\n";

	int ans{ 0 };
	evenDigits(9223372036854775806, ans);
	std::cout << "Number of even digit's: " << ans;

	return 0;
}