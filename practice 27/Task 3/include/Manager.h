#pragma once
#include "Employee.h"
#include <vector>

class Manager : public Employee {
private:
	int teamID;
	bool isTeamBusy;
	std::vector<Employee*> team;

public:
	Manager(const std::string& name_manager, const int& employee_co, const int& teamID);

	int getCoEmployees();
	Employee* getEmployee(int& num);

	void companyTask(int& order);

	bool getTeamBusy();
	bool checkBusy();

};