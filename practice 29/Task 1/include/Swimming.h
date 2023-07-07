#pragma once
#include "Talent.h"
#include <iostream>

class Swimming : public Talent {
    void showTalent() override {
        std::cout << "!Swim!";
    }
};