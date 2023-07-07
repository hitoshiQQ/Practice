#pragma once
#include "Talent.h"
#include <iostream>

class Dancing : public Talent {
    void showTalent() override {
        std::cout << "!Dance!";
    }
};