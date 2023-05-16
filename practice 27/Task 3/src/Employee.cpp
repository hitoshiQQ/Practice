#include "Employee.h"

std::string Employee::getNameEmployee() {
	return this->name;
}

void Employee::setNameEmployee(const std::string& name) {
	this->name = name;
}

std::string  Employee::getTask() {
	std::string str;
	switch (this->task) {
	   case NONE: {
		   str = "none";
		   break;
	   }
	   case A: {
		   str = "A";
		   break;
	   }
	   case B: {
		   str = "B";
		   break;
	   }
	   case C: {
		   str = "C";
		   break;
	   }
	}
	return str;
}

void Employee::setTask(const TASK_TYPE& task) {
	this->task = task;
}

bool Employee::isBusy() {
	return this->task != NONE;
}