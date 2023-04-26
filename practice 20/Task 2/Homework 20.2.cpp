#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

void checkNum(int& const h, int& const w) {
	if (std::cin.fail() || std::cin.peek() != '\n' || h <= 0 || w <= 0)
	{
		std::cerr << "\nError.\nTry again!";
		std::cin >> h >> w;
		checkNum(h, w);
	}
}

void processPictureCreate(const int& const h, const int& const w) {
	std::srand(std::time(nullptr));
	std::ofstream file("picture.txt");
	for (int j = 0; j < h; ++j) {
		for (int i = 0; i < w; ++i) {
			file << std::rand() % 2;
		}
		file << std::endl;
	}
	file.close();
	std::cout << "\n\t\tProcess done!\n";
}

int main() {
	std::cout << "\t\tDrawing random pictures\n\n";

	int height{0}, width{0};
	std::cout << "Enter height and width (pixel): ";
	std::cin >> height >> width;
	checkNum(height, width);
	processPictureCreate(height, width);

	return 0;
}