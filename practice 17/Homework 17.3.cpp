#include <iostream>

bool check_substring(const char* str, const char* substr) {
	int j{ 0 }, i{ 0 };
	bool coincid = true;

	while (*(str + j + i) != '\0') {
		j = 0;
		coincid = true;
		while ((*(substr + j) != '\0') && (*(str + j + i) != '\0')) {
			if ((*(substr + j) != (*(str + j + i)))) {
				coincid = false;
				break;
			}
			++j;
		}
		if (coincid) {
			return true;
		}
		++i;
	}
	return false;
}


int main() {
	std::cout << "\t\tTask 3\n\n";

	const char* a = "Hello world";
	const char* b = "wor";
	const char* c = "banana";

	std::cout << (check_substring(a, b) ? "\nTRUE!" : "\nFALSE!") << "  "
		<< (check_substring(a, c) ? "\nTRUE!" : "\nFALSE!");
}