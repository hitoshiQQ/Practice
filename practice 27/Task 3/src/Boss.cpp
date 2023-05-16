#include <iostream>
#include "Boss.h"

Boss::Boss(const std::string& name) {
	this->setNameEmployee(name);
}

Boss::~Boss() {
	int teamsCO = this->teams.size();
	for (int j = 0; j < teamsCO; ++j) {
		Manager* team = teams[j];
		int employeeCO = team->getCoEmployees();
		for (int i = 0; i < employeeCO; ++i) {
			Employee* employee = team->getEmployee(i);
			delete employee;
		}
		delete team;
	}
}

void Boss::addTeam(Manager* _team) {
	this->teams.push_back(_team);
}

void Boss::setOrder() {
	int bossOrder;
	std::cout << "\nEnter number of boss's oreder: ";
	std::cin >> bossOrder;
	std::system("clear");
	for (int j = 0; j < teams.size(); ++j) {
		teams[j]->companyTask(bossOrder);
	}
}

bool Boss::allTeamBusy() {
	for (int j = 0; j < teams.size(); ++j)
	{
		if (!teams[j]->getTeamBusy()) {
			return false;
		}			
	}
	return true;
}


Boss* createCompany() {
	std::cout << "\n\nEnter name of company boss: ";
	std::string boss_name;
	std::cin >> boss_name;
	Boss* companyBoss = new Boss(boss_name);
	int teamsCO;
	std::cout << "\nEnter count of teams: ";
	std::cin >> teamsCO;
	for (int id = 1; id <= teamsCO; ++id) {
		std::string manager_name;
		std::cout << "\nEnter manager name of team #" << id << ": ";
		std::cin >> manager_name;
		int employeeCO;
		std::cout << "\nEnter count of employees: ";
		std::cin >> employeeCO;
		
		auto* _team = new Manager(manager_name, employeeCO, id);
		for (int j = 0; j < employeeCO; ++j) {
			std::string employee_name;
			std::cout << "\nEnter name of employee #" << j + 1 << " from team #" << id << ": ";
			std::cin >> employee_name;
			Employee* employee = _team->getEmployee(j);
			employee->setNameEmployee(employee_name);
		}
		companyBoss->addTeam(_team);
	}
	return companyBoss;
}

void deleteCompany(Boss* boss) {
	delete boss;
	boss = nullptr;
}