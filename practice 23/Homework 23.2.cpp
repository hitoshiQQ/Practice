#include <iostream>

#define SPRING 1
#define SUMMER 2
#define AUTUMN 3
#define WINTER 4

#define CURRENT_SEASON SPRING

#if CURRENT_SEASON <=4 && CURRENT_SEASON > 0

int main() {

#if CURRENT_SEASON == SUMMER
	std::cout << "Summer!\n";
#elif CURRENT_SEASON == AUTUMN
	std::cout << "Autumn.\n";
#elif CURRENT_SEASON == AUTUMN
	std::cout << "Winter!\n";
#else CURRENT_SEASON == SPRING
	std::cout << "Spring.\n";
#endif
	return 0;
}
#endif