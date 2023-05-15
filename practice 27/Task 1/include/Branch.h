#include <iostream>
#include <vector>
#pragma once

class Branch {
	std::string name = "none";
	Branch* parent = nullptr;
	std::vector<Branch*>branch;

public:
	Branch(const std::string& name, Branch* parent);
	int size();

	Branch* addDaughter(Branch* _branch);
	Branch* getBranchAt(int index);
	Branch* getParent() const;

	const std::string& findName() const;
	const std::vector<Branch*>& findBranch()const;
	
};