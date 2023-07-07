#pragma once
#pragma once
#include "Talent.h"
#include <iostream>

class Counting : public Talent {
    void showTalent() override {
        std::cout << "!Count!";
    }
};