#pragma once
#include <iostream>
#include <string>
#include <algorithm>


void showCommand() {

    std::cout << "\n=========================================================";
    std::cout << "\n   help   - view commands                                ";
    std::cout << "\n   show   - browse the store                             ";
    std::cout << "\n   add    - add product's to basket                      ";
    std::cout << "\n   list   - view product's in basket                     ";
    std::cout << "\n   remove - remove product's from basket                 ";
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