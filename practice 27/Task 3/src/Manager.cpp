#include <iostream>
#include "Manager.h"

Manager::Manager(const std::string& name_manager, const int& employee_co, const int& teamID) {
	this->setNameEmployee(name_manager);
	this->isTeamBusy = false;
	this->teamID = teamID;
	for (int j = 0; j < employee_co; ++j) {
		auto* _employee = new Employee;
		this->team.push_back(_employee);
	}
}

int Manager::getCoEmployees() {
	return this->team.size();
}

Employee* Manager::getEmployee(int& num) {
	if (num < 0) {
		return nullptr;
	}
	if (num >= this->team.size()) {
		return nullptr;
	}
	return this->team[num];
}

void Manager::companyTask(int& order) {
	if (!isTeamBusy) {
		std::srand(this->teamID + order);
		int tasksCO = rand() % (this->team.size() + 1);
		std::cout << "\nManager: " << this->getNameEmployee() << "||\n Has got: " << tasksCO
			<< " task's\n";
		for (int j = 0; j < team.size() && tasksCO >0; ++j) {
			TASK_TYPE _task = TASK_TYPE(rand() % AmountTask);
			if (_task != NONE && !team[j]->isBusy()) {
				team[j]->setTask(_task);
				std::cout << team[j]->getNameEmployee() << " has got task " 
					<< team[j]->getTask() << std::endl;
				--tasksCO;
			}
		}
		isTeamBusy = this->checkBusy();
		if (isTeamBusy) {
			std::cout << "\nTeam #" << this->teamID << " busy now!\n";
		}
	}
	else {
		std::cout<<"\nTeam #" << this->teamID << " busy now!\n";
	}
}

bool Manager::getTeamBusy() {
	return this->isTeamBusy;
}

bool Manager::checkBusy() {
	for (int j = 0; j < team.size(); ++j) {
		if (!team[j]->isBusy()) {
			return false;
		}
	}
	return true;
}