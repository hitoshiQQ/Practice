#pragma once
#include "Manager.h"

class Boss : public Employee {
private:
	std::vector<Manager*> teams;

public:
	explicit Boss(const std::string& name);
	~Boss();

	void addTeam(Manager* _team);
	void setOrder();
	bool allTeamBusy();
};

Boss* createCompany();
void deleteCompany(Boss* boss);