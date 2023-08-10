#pragma once
#include <iostream>
#include <map>
#include <string>

class OnlineMarket {
private:
	const std::string invArg = "\nInvalid arguments exception: ";
	std::map<std::string, int> products;
	std::map<std::string, int> basket;

public:
	OnlineMarket() = default;
	explicit OnlineMarket(const std::map<std::string, int>& products);

	void productPreview();

	void addBasket();
	int enterProductCount();
	std::string enterArticle();
	void removeBasket();
	void basketPreview();
};