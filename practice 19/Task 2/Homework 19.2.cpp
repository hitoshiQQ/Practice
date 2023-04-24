#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::cout << "\t\tText viewer\n\n";

	std::string filePath;
	std::cout << "Enter file path: ";
	std::cin >> filePath;
	std::ifstream file;
	
	file.open(filePath);
	while (!file.eof()) {
		std::string temp;
		std::getline(file, temp);
		std::cout << temp << std::endl;
	}
	file.close();
}