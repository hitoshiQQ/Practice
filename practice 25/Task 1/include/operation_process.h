#pragma once
#include "surgical_tools.h"

void enterOperation(std::vector <MyCommand>& cmd);

bool checkOperation(std::vector <MyCommand>& op);

void processOperation(std::vector <MyCommand>& op);