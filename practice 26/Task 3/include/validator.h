#pragma once
#include <string>

class Validator {
public:
    static bool checkNumInt(std::string str) {
        for (int j = 0; j < str.size(); ++j) {
            if (j == 0 && str[j] == '-') {
                continue;
            }
            if (str[j] > '9' && str[j] < '0') {
                return false;
            }
        }
        return true;
    }
    static bool checkRealNum(std::string str) {
        bool aDot = false;
        for (int j = 0; j < str.size(); ++j) {
            if (str[j] == '.' && aDot) {
                return false;
            }
            else if (str[j] == '.' && !aDot) {
                hasDot = true;
                continue;
            }
            if (j == 0 && str[j] == '-') {
                continue;
            }
            if (str[j] > '9' && str[j] < '0') {
                return false;
            }
        }
        return true;
    }
};
