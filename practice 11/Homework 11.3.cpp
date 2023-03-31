#include <string>
#include <regex>
#include "Source.h"


bool is_valid_digit(std::string ip) {
	int sum = stoi(ip);
	if (sum > 255 || sum < 0) {
		return false;
	}
}
bool is_valid_alpha(std::string ip, int size) {
	std::regex r("[A-Za-z]*");
	while (regex_match(ip, r)) {
		return false;
	}
}

bool check_ip_address(std::string ip) {
	 
	std::string delim{ "." };
	size_t delim_size = delim.size();
	std::string temp;
	while (true) {
		temp = ip.substr(0, ip.find(delim));
		if (temp.size() != 0) {
			if (!(is_valid_alpha(temp,temp.size()))) {
				return false;
				break;
			}
			if ((temp.size() > 1 && temp[0] == '0')) {
				return false;
				break;
			}
			if (!(is_valid_digit(temp))) {
				return false;
				break;
			}
				
			
		}
		if (temp.size() == ip.size()) {
			break;
		}
		else {
			ip = ip.substr(temp.size() + delim_size);
		}
	}
}

bool check_dat(std::string ip) {
	int countDat{ 0 };
	for (int j = 0; j < ip.size(); ++j) {
		if (ip[j] == '.')
			++countDat;
	}
	if (countDat != 3)
		return false;
}
bool amount_dat(std::string ip) {
	for (int j = 1; j < ip.size() - 1; ++j) {
		if (ip[j - 1] == '.' && ip[j] == '.') {
			return false;
		}
	}
}

void valid_ip(std::string ip) {
	if (check_ip_address(ip) && check_dat(ip)
		&&amount_dat(ip)) {
		cout << "\nValid\n";
	}
	else {
		cout << "\nInvalid\n";
	}
}

int main() {

	cout << "\t\tValidating the IP address\n\n";

	std::string ip;
	cin >> ip;
	valid_ip(ip);
}