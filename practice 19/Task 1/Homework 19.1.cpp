#include <iostream>
#include <fstream>

std::string toLower(std::string& const str) {
	std::string newStr;
	for (char j : str) {
		newStr += (char)tolower(j);
	}
	return newStr;
}

bool equalIgnore(std::string& const str1, std::string& const str2) {
	if (toLower(str1) == toLower(str2)) {
		return true;
	}
	return false;
}

bool charIsSign(char a) {
	std::string sign = ",.;:'\"*?^!%";
	for (char j : sign) {
		if (a == j) {
			return true;
		}
	}
	return false;
}

std::string removeSign(std::string& const str) {
	std::string newStr;
	for (char j : str) {
		if (!charIsSign(j)) {
			newStr += j;
		}
	}
	return newStr;
}

int main() {
	std::cout << "\t\tWord's finder\n\n";

	std::string match_word, current_word;
	int co = 0;
	const char* file = "words.txt";
	std::cout << "Input word to count:" << std::endl;
	std::cin >> match_word;

	std::ifstream words;
	words.open(file);

	while (!words.eof()) {
		words >> current_word;
		current_word = removeSign(current_word);


		if (equalIgnore(current_word,match_word)) {
			++co;
		} 
	}
	std::cout << "Matches counter: " << co << std::endl;
	words.close();

	return 0;
}