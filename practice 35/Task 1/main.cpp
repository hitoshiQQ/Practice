#include <iostream>
#include <vector>
#include "initializer_list"

template <typename T>
class Test {
private:
	std::vector<T> pices;

public:
	Test(const std::initializer_list<T>& in_pice) {

		pices = in_pice;
	}

	std::vector<T> getVector() {

		return pices;
	}
};

int main(){

	Test<int> t = { 9,2,3,4,5 };
	for (auto j : t.getVector()) {

		std::cout << j << " ";
	}
}
