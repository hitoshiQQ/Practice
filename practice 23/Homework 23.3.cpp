#include <iostream>

#define OPTIMAL_AMOUNT 20;

int wagonOccupancy(int iter) {
	int pass;
	std::cout << "\nWagon# " << iter << "\nEnter amount passanger's: ";
	std::cin >> pass;
	return pass;
}

bool checkWagonOccupancy(int pass_amt) {
	return pass_amt == OPTIMAL_AMOUNT;
}

bool checkOverWagonOccupanncy(int  pass_amt) {
	return pass_amt > OPTIMAL_AMOUNT;
}


#define PROCESS_WAGON(new_wagon) \
                  int j = 1; \
                  while(j<=new_wagon){ \
                      int load = wagonOccupancy(j++); \
                      if(checkWagonOccupancy(load)) { \
                         optimal_wagons++; \
					  } else { \
						    checkOverWagonOccupanncy(load) ? overload_wagons++ : incomplect_wagons++; \
                      } \
                      pass_sum += load; \
                  }

int main() {
	int pass_sum = 0;
	int optimal_wagons = 0;
	int overload_wagons = 0;
	int incomplect_wagons = 0;

	PROCESS_WAGON(10);

	std::cout << "\n\nOverloaded wagon's: " << overload_wagons << std::endl;
	std::cout << "Incomplect wagon's: " << incomplect_wagons << std::endl;
	std::cout << "Optimal loaded wagon's: " << optimal_wagons << std::endl;
	std::cout << "The total number of passenger's on the train: " << pass_sum << std::endl;

	return 0;
}