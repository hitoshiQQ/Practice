#pragma once
#include <string>
#include "TaskType.h"

class Employee {
private:
	std::string name = "unkown";
	TASK_TYPE task = NONE;
	
public:
	std::string getNameEmployee();
	void setNameEmployee(const std::string& name);

	std::string getTask();
	void setTask(const TASK_TYPE& task);

	bool isBusy();
};