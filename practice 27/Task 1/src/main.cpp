#include <iostream>
#include "Tree.h"
#include <string>

int main() {
	Tree tree;
	tree.createTree();

	tree.print();
	std::string name;
	do {
		std::cout << "\nEnter elf name: ";
		getline(std::cin, name);
		if (name != "stop") {
			tree.printFound(name);
		}
	} while (name != "stop");
	
}