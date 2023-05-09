#pragma once
#include "coordinate.h"
#include <vector>

enum Command {
	SCALPEL,
	HEMOSTAT,
	TWEEZERS,
	SUTURE,
	FINISH,
	NONE = 99
};

const std::vector<std::string> command_str = {
	"scalpel",
	"hemostat",
	"tweezers",
	"suture",
	"finish"
};

struct MyCommand {
	Command _command;
	std::vector<Coordinate> coords;
};

void scalpel(std::vector<Coordinate>& c);

void hemostat(std::vector<Coordinate>& c);

void tweezers(std::vector<Coordinate>& c);

void suture(std::vector<Coordinate>& c);

enum Command enterCommand();

void fillCommand(MyCommand& my_cmd);

void enterCommandCoordinate(std::vector<Coordinate>& crd, int amount);

void processCommand(MyCommand& my_cmd);
