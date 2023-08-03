#pragma once
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

void toLower(std::string& str) {
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

std::string getCommand() {
	std::string str;
	getline(std::cin, str);
	return str;
}

bool findMovie(std::string& cmd, const nlohmann::json& data) {
	bool not_found = true;

	for (auto& movie : data) {
		std::string name = movie["Name"];
		toLower(name);
		if (name.find(cmd) != std::string::npos) {
			not_found = false;
			std::cout << "\nMovie find result:";
			std::cout << "\tName: " << movie["Name"] << std::endl;
			std::cout << "\tCountries: " << movie["Countries"] << std::endl;
			std::cout << "\tYear: " << movie["Year"] << std::endl;
			std::cout << "\tDirected by: " << movie["Directed by"] << std::endl;
			std::cout << "\tWritten by: " << movie["Written by"] << std::endl;
			std::cout << "\tProduced by: " << movie["Produced by"] << std::endl;
			std::cout << "\tCinematography: " << movie["Cinematography"] << std::endl;
			std::cout << "\tEdited by: " << movie["Edited by"] << std::endl;
			std::cout << "\tMusic by: " << movie["Music by"] << std::endl;
			std::cout << "\tDistributed by: " << movie["Distributed by"] << std::endl;
			std::cout << "\tInvited starring: \n";
			for (auto& actor : movie.at("Starring")) {
				std::cout << "\t\t\t\t" << actor.front() << " || " << actor.back() << std::endl;
			}
		}
	}
	if (!not_found) {
		return true;
	}
	std::cout << "\nMovie not found!";
	return false;
}

void findActor(std::string& cmd, const nlohmann::json& data) {
	bool not_found = true;
	
	for (auto& movie : data) {
		for (auto& role : movie["Starring"]) {
			std::string actor = role.front();
			if (actor.find(cmd) != std::string::npos) {
				if (not_found) {
					std::cout << "\n Actor find result:\n";
					not_found = false;
				}
				std::cout << "\t" << role.front() << " || "
					<< role.back() << " || " << movie["Name"] << std::endl;
			}
		}
	}
	if (not_found) {
		std::cout << "\nActor not found!";
	}
}