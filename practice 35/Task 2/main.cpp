#include <iostream>
#include <vector>
#include <initializer_list>
#include <unordered_set>
#include <memory>
#include <algorithm>

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
   
	Test <int> t = { 6,2,3,4,3,7,8,7,9 };
	for (auto j : t.getVector()) {

		std::cout << j << " ";
	}
	std::cout << "\n\n";

	auto a = [](const std::vector<int>& array) {

		std::unordered_set<int> arrayUS;

		for (auto j : array) {

			arrayUS.insert(j);
		}

		auto arrayU = std::make_unique<std::vector<int>>();

		for (auto j : arrayUS) {

			arrayU->push_back(j);
		}

		return arrayU;

	}(t.getVector());

	for (auto j : *a) {

		std::cout << j << " ";
	}
}
