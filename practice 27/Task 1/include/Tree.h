#pragma once
#include "Branch.h"

class Tree {
	bool check_find;
	Branch* find;
	Branch* root = new Branch("ROOT", nullptr);
	
public:

	Branch* createTree();
	Branch* getRoot() const;

	void print();
	void printFound(const std::string& name);
	void displayTree(const std::string& branch, Branch* parent);
	void findNameOnTree(const std::string& name, Branch* parent);

};