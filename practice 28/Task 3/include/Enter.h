#pragma once
#include <iostream>
#include <mutex>
#include <string>

class Validator {
public:
    static bool checkNumInt(std::string str);
    static bool checkRealNum(std::string str);
};

class Enters {
public:
    static std::mutex access;
    static double enterDouble(const std::string& str);
    static int enterInt(const std::string& str);
    static std::string enterStr(std::string str);
    static double enterPositionDouble(const std::string& str);
    static void print(std::string str);
};