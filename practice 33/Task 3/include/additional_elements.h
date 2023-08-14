#pragma once
#include <iostream>
#include <string>
#include <algorithm>


void showCommand() {

    std::cout << "\n=========================================================";
    std::cout << "\n   help   - view commands                                ";
    std::cout << "\n                                                         ";
    std::cout << "\n   add    - add record                                   ";
    std::cout << "\n   find   - search for all records by specified key      ";
    std::cout << "\n   list   - view of all registry entries                 ";
    std::cout << "\n   remove - deleting all records with the specified key  ";
    std::cout << "\n   exit                                                  ";
    std::cout << "\n=======================================================\n";
}

void toLower(std::string& str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

std::string getCommand() {
    std::string str;
    std::getline(std::cin, str);
    toLower(str);
    return str;
}
