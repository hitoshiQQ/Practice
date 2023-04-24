#include <iostream>
#include <vector>
#include <fstream>

void readFile(const std::string const PathOfFile, std::vector<std::string>& const firstName,
	std::vector<std::string>& const surName, std::vector<std::string>& const date,
	std::vector<int>& const salary) {
	std::ifstream file;
	file.open(PathOfFile);
	while (!file.eof()) {
		std::string first_name, sur_name, date_temp;
		int salary_temp;
		file >> first_name >> sur_name >> salary_temp >> date_temp;
		firstName.push_back(first_name);
		surName.push_back(sur_name);
		salary.push_back(salary_temp);
		date.push_back(date_temp);
	}
	file.close();
}

int sum(std::vector<int>& const salary) {
	int sum{ 0 };
	for (int j = 0; j < salary.size(); ++j) {
		sum += salary[j];
	}
	return sum;
}

int findMaxIndex(const std::vector<int>& const vec) {
	int ind = 0, max = vec[0];
	for (int j = 0; j < vec.size(); ++j) {
		if (vec[j] > max) {
			ind = j;
			max = vec[j];
		}
	}
	return ind;
}

std::string findMaxSalary(std::vector<std::string>& const firstName,
	std::vector<std::string>& const surName, std::vector<int>& const salary) {
	int ind = findMaxIndex(salary);
	return firstName[ind] + " " + surName[ind];
}

int main() {
	std::cout << "\t\tReading the statement\n\n";

	std::vector<std::string> firstName, surName, date;
	std::vector<int> salary;
	readFile("Statement.txt", firstName, surName, date, salary);

	std::cout << "Total amount of salary: " << sum(salary) << std::endl;
	std::cout << "Max salary: " << findMaxSalary(firstName, surName, salary)<<std::endl;

	return 0;
}