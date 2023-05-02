#include <iostream>
#include <map>
#include <string>

std::string toLower(const std::string& const str) {
	std::string res;
	for (char j : str) {
		if (j != ' ') {
			res.push_back((char)tolower(j));
		}
	}
	return res;
}

std::map<char, int> stringToMap(const std::string& const str) {
	std::string txt = toLower(str);
	std::map<char, int> map;
	for (char j : txt) {
		if (map.find(j) == map.end()) {
			map.insert(std::pair<char, int>(j, 0));
		}
		map[j] += 1;
	}
	return map;
}

bool compare(std::string& const str1, std::string& str2) {
	std::map<char, int> map1 = stringToMap(str1);
	std::map<char, int> map2 = stringToMap(str2);
	if (map1.size() != map2.size()) {
		return false;
	}

	auto j = map1.begin();
	auto i = map2.begin();

	while (j != map1.end()) {
		if ((j->first != i->first) || (j->second != i->second)) {
			return false;
		}
		++j; ++i;
	}
	return true;
}

int main() {
	std::cout << "\t\tAnagrams\n\n";
	setlocale(LC_ALL, "ru");
	
	std::string str1[]{ "Кабан","Банка" };
	std::string str2[]{ "Актер","Терка" };
	std::string str3[]{ "Не","Анаграмма" };

	std::cout << str1[0] << " || " << str1[1];
	std::cout << (compare(str1[0], str1[1]) ? "\tAnagram's\n" : "\tNot anargam's\n");

	std::cout << str2[0] << " || " << str2[1];
	std::cout << (compare(str2[0], str2[1]) ? "\tAnagram's\n" : "\tNot anargam's\n");

	std::cout << str3[0] << " || " << str3[1];
	std::cout << (compare(str3[0], str3[1]) ? "\tAnagram's\n" : "\tNot anargam's\n");

	return 0;
}