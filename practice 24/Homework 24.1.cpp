#include <iostream>
#include <ctime>
#include <vector>

struct TimeTask {
	std::string task_name;
	std::time_t st_time;
	std::time_t end_time;
};

void helpWall() {
	std::cout << "\n\n\t\tbegin\t- for start working\n";
	std::cout << "\t\tstatus\t- for print task\n";
	std::cout << "\t\tend\t- for end working task\n";
	std::cout << "\t\texit\t- exit\n";
}

std::string toLower(const std::string& const str) {
	std::string res;
	for (char j : str) {
		if (j != ' ') {
			res.push_back((char)tolower(j));
		}
	}
	return res;
}

std::string enterTask(const std::string& const str) {
	std::cout << str;
	std::string res;
	std::cin >> res;
	toLower(res);

	return res;
}

void startTask(std::vector<TimeTask>& task) {
	TimeTask _task;
	_task.task_name = enterTask("\nEnter name task: ");
	_task.st_time = std::time(nullptr);
	_task.end_time = 0;
	task.push_back(_task);
}

void endTask(std::vector<TimeTask>& task) {
	std::time_t end_time = std::time(nullptr);
	for (int j = 0; j < task.size(); ++j) {
		if (task[j].end_time == 0) {
			task[j].end_time = end_time;
		}
	}
}

void printTask(std::vector<TimeTask>& task) {
	for (int j = 0; j < task.size(); ++j) {
		if (task[j].end_time != 0) {
			std::cout << task[j].task_name << " | " << task[j].end_time - task[j].st_time << " (sec)\n";
		}else {
			std::cout << "\nCurrent task: " << task[j].task_name << " || Passed time: " << std::time(nullptr)
				- task[j].st_time << std::endl;
		}
	}
}

void process(std::vector<TimeTask>& curr_task) {
	std::string comm;
	do {
		helpWall();
		comm = enterTask("\nEnter next task: ");
		if (comm == "begin") {
			endTask(curr_task);
			startTask(curr_task);
		}else if (comm == "end") {
			endTask(curr_task);
		}else if (comm == "status") {
			printTask(curr_task);
		}else if (comm == "exit") {
			return;
		}
	} while (true);
	
}


int main() {
	std::cout << "\t\tTime tracking\n\n";

	std::vector<TimeTask> task;
	process(task);

	return 0;
}