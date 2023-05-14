#pragma once
#include <string>

class Validator {
public:
    static bool checkNumInt(std::string str) {
#define N (str[i])
        for (int i = 0; i < str.size(); ++i) {
            if (i == 0 && N == '-') continue;
            if (N > '9' && N < '0') return false;
        }
        return true;
    }
    static bool checkRealNum(std::string str) {
        bool hasDot = false;
        for (int i = 0; i < str.size(); ++i) {
            if (N == '.' && hasDot) return false;
            else if (N == '.' && !hasDot) {
                hasDot = true;
                continue;
            }
            if (i == 0 && N == '-') continue;
            if (N > '9' && N < '0') return false;
        }
        return true;
    }
#undef N

};