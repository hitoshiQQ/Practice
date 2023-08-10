#include "online_market.h"

OnlineMarket::OnlineMarket(const std::map<std::string, int>& products) :products(products) {}

void OnlineMarket::productPreview() {
	if (!products.empty()) {
		std::cout << "\n\nProducts: ";
		for (auto& product : products) {
			std::cout << "\n\t||Article: " << product.first << "\n\t||Count: " << product.second << std::endl;
		}
	}else {
		throw std::invalid_argument("\nExpetion: empty product database!");
	}
}


void OnlineMarket::addBasket() {
	std::pair <std::string, int> pair{};

	pair.first = enterArticle();
	auto f_pair = products.find(pair.first);
	if (f_pair == products.end()) {
		throw std::invalid_argument(invArg + "this item is not available\n");
	}
	if (f_pair->second == 0) {
		throw std::range_error("\nThis item is out of stock");
	}

	pair.second = enterProductCount();
	if (pair.second > f_pair->second) {
		char ch;
		std::cout << "\n\tAvailable: " << f_pair->second << " product count \"" << f_pair->first << "\"";
		std::cout << "\n\tYou take this amount? ";
		std::cout << "\n\t Enter your opinion y[take]/n[choose other product]: ";
		std::cin >> ch;
		if (ch == 'n')
			throw std::invalid_argument("\n\t\tSelect another product!");
		pair.second = f_pair->second;
	}
	f_pair->second -= pair.second;
	

	auto add = basket.find(pair.first);
	if (add == basket.end()) {
		basket.emplace(pair.first, pair.second);
		std::cout << "\n\nProduct added: ";
	}else {
		add->second += pair.second;
		pair.second = add->second;
		std::cout << "\n\t\tThe amount of the item has been changed to: ";
	}
	std::cout << "\nArticle: " << pair.first << "|| Count: " << pair.second << std::endl;
}


int OnlineMarket::enterProductCount() {
	int count;
	std::cout << "\t\t\tEnter count: ";
	std::cin >> count;
	if (count <= 0) {
		throw std::invalid_argument(invArg + "Quantity of goods is less than or equal to zero!");
	}
	return count;
}

std::string OnlineMarket::enterArticle() {
	std::string article;
	std::cout << "\t\t\tEnter article: ";
	getline(std::cin, article);
	if (article.empty()) {
		throw std::invalid_argument(invArg + "Wrong article");
	}
	return article;
}

void OnlineMarket::removeBasket() {
	std::pair<std::string, int> pair{};

	pair.first = enterArticle();

	auto f_pair = basket.find(pair.first);
	if (f_pair == basket.end()) {
		throw std::invalid_argument(invArg + "This article is not available");
	}

	std::cout << "\n\n\tCurrent basket: " << f_pair->second << "product count: " << f_pair->first << "How much need to remove?\n";
	pair.second = enterProductCount();

	if (pair.second > f_pair->second) {
		char ch;
		std::cout << "\n\tCurrent basket: " << f_pair->second << " product count.";
		std::cout << "\n\tAre you sure you want to remove this up?";
		std::cout << "\n\tEnter your opinion y[remove]/n[don't remove]: ";
		std::cin >> ch;
		if (ch == 'n') {
			throw std::invalid_argument("\n\t\tContinue shopping!");
		}
		pair.second = f_pair->second;
	}

	f_pair->second -= pair.second;
	std::cout << "\n\tCurrent count product in the basket: " << f_pair->second << std::endl;
	if (f_pair->second == 0) {
		basket.erase(f_pair);
		std::cout << "\n\t\tProduct removed from basket!";
	}

	auto shop_pair = products.find(pair.first);
	if (shop_pair == products.end()) {
		throw std::range_error("Exception: product not found in database");
		shop_pair->second += pair.second;
	}
}

void OnlineMarket::basketPreview() {
	if (!basket.empty()) {
		std::cout << "\n\nCurrent basket:";
		for (auto& product : basket) {
			std::cout << "\n\t\tArticle: " << product.first << "\n\t\tCount: " << product.second << std::endl;
		}
	}else {
		std::cout << "\nBasket is empty!";
	}
}