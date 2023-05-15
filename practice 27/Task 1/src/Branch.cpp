#include <cassert>
#include "Branch.h"

Branch::Branch(const std::string& name, Branch* parent) {
	this->name = name;
	this->parent = parent;
}

int Branch::size() {
	return (int)branch.size();
}

Branch* Branch::addDaughter(Branch* _branch) {
	assert(_branch != nullptr);
	branch.push_back((Branch* const)_branch);
	return branch.at(branch.size() - 1);
}

Branch* Branch::getBranchAt(int index) {
	if (index < 0) {
		return nullptr;
	}
	if (index > branch.size()) {
		return nullptr;
	}
	return branch.at(index);
}

Branch* Branch::getParent() const {
	return parent;
}

const std::string& Branch::findName() const {
	return name;
}

const std::vector<Branch*>& Branch::findBranch()const {
	return branch;
}



