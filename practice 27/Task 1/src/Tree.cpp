#include <cassert>
#include <random>
#include <string>
#include "Tree.h"

Branch* Tree::createTree() {

	std::random_device _r;
	std::mt19937 gen(_r());
	
	for (int j = 0; j < 2; ++j) {
		std::string tree_name = "A" + std::to_string(j + 1);
		auto* tree = root->addDaughter(new Branch("Tree" + tree_name, root));

		for (int i = 0; i < (rand() % 3 + 3); ++i) {
			std::cout << "Enter elf name: ";
			std::string b_name;
			std::cin >> b_name;
			auto* branch = tree->addDaughter(new Branch(b_name, tree));

			for (int q = 0; q < (rand() % 2 + 2); ++q) {
				std::cout << "Enter elf name: ";
				std::string c_name;
				std::cin >> c_name;
				branch->addDaughter(new Branch(c_name, branch));
			}
		}
	}
	return root;
}

Branch* Tree::getRoot() const {
	return root;
}

void Tree::print() {
	displayTree("", root);
}

void Tree::printFound(const std::string& name) {
	find = nullptr;
	check_find = false;
	findNameOnTree((std::string&)name, root);
	if (find != nullptr) {
		std::cout << "\t\tBig branch neighbors: ";
		std::cout << find->findName() << std::endl;
		displayTree("", find);
	}else {
		std::cout << "\n\t\t!Not founds!";
	}
}

void Tree::displayTree(const std::string& branch, Branch* parent) {
	assert(parent != nullptr);
	if (parent->size() == 0) {
		return;
	}
	for (int j = 0; j < parent->size(); ++j) {
		std::cout << branch << parent->getBranchAt(j)->findName() << std::endl;
		if (parent->getBranchAt(j) > 0) {
			displayTree((branch + "\t"), parent->getBranchAt(j));
		}
	}
}

void Tree::findNameOnTree(const std::string& name, Branch* parent) {
	if (check_find || parent->size() == 0) {
		return;
	}
	for (int j = 0; j < parent->size(); ++j) {
		if (name == parent->getBranchAt(j)->findName()) {
			find = parent->getBranchAt(j);
			if (find->size() == 0) {
				find = find->getParent();
			}
			check_find = true;
			return;
		}
		if (parent->getBranchAt(j)->size() > 0) {
			findNameOnTree(name, parent->getBranchAt(j));
		}
	}
}