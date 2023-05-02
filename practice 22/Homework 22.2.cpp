#include <iostream>
#include <string>
#include <map>

void helpWall() {
	std::cout << "next\t- for let the next\n";
	std::cout << "exit\t- exit\n";
}

std::string enterData(std::string str) {
	std::string enter;
	std::cout << str;
	std::cin >> enter;
	return enter;
}

void addQueue(std::map<std::string, int>& queue,const std::string& const enter) {
	std::map<std::string, int>::iterator iter = queue.find(enter);
	if (iter == queue.end()) {
		queue.insert(std::pair<std::string, int>(enter, 1));
	}else {
		++iter->second;
	}
}

void turndownQueue(std::map<std::string, int>& queue) {
	std::map<std::string, int>::iterator iter = queue.begin();
	if (queue.size() == 0) {
		std::cout << "\t\tThere is nothing\n";
		return;
	}

	std::cout << "->" << iter->first << std::endl;
	--iter->second;
	if (iter->second == 0) {
		queue.erase(iter);
	}
}

void processQueue(std::map<std::string, int>& queue) {
	std::string command;
	do {
		command = enterData("Add next: ");

		if (command == "next") {
			turndownQueue(queue);
		}else {
			addQueue(queue, command);
		}

	} while (command != "exit");

}
int main() {
	std::cout << "\t\tRegistry\n\n";
	std::map<std::string, int> queue;
	processQueue(queue);

	return 0;
}