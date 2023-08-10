#pragma once
#include <iostream>
#include "online_market.h"
#include "additional_elements.h"

void menu() {
	OnlineMarket shopProducts({ {"T-Shirt",5},{"Sweater",5},{"Turtleneck",5},{"Sport-Suit",10},{"Jacket",5},{"Shoes",15},{"Sneakers",10},{"Cap",3} });

	try {
		shopProducts.productPreview();
	}
	catch (const std::invalid_argument& e) {
		std::cerr << e.what();
		return;
	}

	std::string cmd;
	showCommand();

	do {
		std::cin.clear();
		fflush(stdin);

		std::cout << "\nEnter your opinion: ";
		cmd = getCommand();

		if (cmd == "add") {
			try {
				shopProducts.addBasket();
			}catch (const std::invalid_argument& e) {
				std::cout << e.what();
			}catch (const std::range_error& l) {
				std::cout << l.what();
			}
		}else if (cmd == "show") {
			shopProducts.productPreview();
		}else if (cmd == "list") {
			shopProducts.basketPreview();
		}else if (cmd == "remove") {
			try {
				shopProducts.removeBasket();
			}catch (const std::invalid_argument& e) {
				std::cout << e.what();
			}catch (const std::range_error& l) {
				std::cout << l.what();
			}
		}else if (cmd == "help") {
			showCommand();
		}
	} while (cmd != "exit");
}