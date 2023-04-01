#include "Source.h"
#include <cassert>




int main(){
	cout << "\t\tAppartment building\n\n";

	std::string surnames[]{ "SidorovA","IvanovA","PetrovA","SidorovB","IvanovB"
		,"PetrovB","SidorovC","IvanovC","PetrovC","SidorovD" };
	int apartmentNumber[]{ 1,2,3,4,5,6,7,8,9,10 };
	
	
	while (true) {
		int choise;
		cout << "\n\nEnter the apartment #"; cin >> choise;
		
		if (std::cin.fail() || std::cin.peek() != '\n'){
			std::cerr << "Error\n";
			

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		assert(choise >= 1 && choise <= 10);

		cout << "In the apartmen #" << apartmentNumber[choise-1] 
			<< " live " << surnames[choise - 1];

	}
	
	return 0;
}