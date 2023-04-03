#include "Source.h"
#include <vector>
#include <cassert>

void get_price(std::vector<float>& prices, std::vector<int>& vec) {
	float sum = 0.f;
	for (int j = 0; j < vec.size(); ++j) {
		if (vec[j] > prices.size()-1 || vec[j] < 0) {
			std::cout << "\nIndex Error's!!!\n";
			return;
		}
		sum += prices[vec[j]];
	}
	cout << sum;
}

int main(){

	std::cout << "\t\tTask 2\n\n";

	std::vector<float> prices{ 2.5,4.25,3.0,10.0 };
	std::vector<int> shoppingPrice{1,1,0,3};
	std::cout << "Total cost: ";
	get_price(prices, shoppingPrice);

	return 0;
}