#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

const int notes = 6;

std::vector<int> banknotes = { 5000, 2000, 1000, 500, 200, 100 };
std::vector<int> atm_cash(notes, 0);
std::vector<int> withdrawal_set(notes, 0);

void initialization(int arr[], const int& const size) {
    for (int j = 0; j < size; ++j) {
        arr[j] = 0;
    }
}

void printATM(const std::vector<int>& const vec) {
    int co = 0;
    for (int j = 0; j < notes; ++j) {
        if (vec[j]) {
            std::cout << banknotes[j] << " RUB  " << vec[j] << std::endl;
            co += vec[j];
        }
    }
    std::cout << "All banknote's: " << co << std::endl;
}

bool isNumber(const std::string& const str) {
    for (int j = 0; j < str.size(); ++j) {
        if (str[j] < '0' || str[j] > '9') {
            return false;
        }
    }     
    return true;
}

void checkPoint() {
    std::ofstream file_atm("atm.bin", std::ios::binary);
    if (file_atm.is_open()) {
        int size = notes;
        file_atm.write((char*)&size, sizeof(int));
        file_atm.write((char*)&banknotes[0], sizeof(int) * size);
        file_atm.write((char*)&atm_cash[0], sizeof(int) * size);
        file_atm.close();
    }
}

void processClient() {
    int vector_size = 0;
    std::ifstream file_atm("atm.bin", std::ios::binary);
    file_atm.read((char*)&vector_size, sizeof(vector_size));
    if (file_atm.is_open()) {
        file_atm.read((char*)&banknotes[0], sizeof(int) * vector_size);
        file_atm.read((char*)&atm_cash[0], sizeof(int) * vector_size);
        file_atm.close();
    }
}

void processEncashment() {
    std::srand(std::time(nullptr));
    int atm_banknotes = 0;
    for (int j = 0; j < 1000 - atm_banknotes; ++j) {
        atm_cash[rand() % 6] += 1;
    }
    checkPoint();
    printATM(atm_cash);
}

std::string enter(std::string str) {
    std::string enter;
    std::cout << str;
    std::cin >> enter;
    return enter;
}


bool isAvailable(int money) {
    std::fill(withdrawal_set.begin(), withdrawal_set.end(), 0);
    for (int i = 0; i < notes; ++i) {
        withdrawal_set[i] = (money / banknotes[i] > atm_cash[i] ? atm_cash[i] : money / banknotes[i]);
        money -= withdrawal_set[i] * banknotes[i];
    }
    return money == 0;
}

bool withdrawal() {
    int money;
    bool isNumberb = false;
    std::string money_str;
    do {
        money_str = enter("Withdrawal [multiple " + std::to_string(banknotes[notes - 1]) + "]:");
        isNumberb = isNumber(money_str);
        if (isNumberb) money = std::stol(money_str);
    } while (!((isNumberb) && (money % banknotes[notes - 1] == 0)));
    if (isAvailable(money)) {
        for (int i = 0; i < notes; ++i) {
            atm_cash[i] -= withdrawal_set[i];
        }
        checkPoint();
        printATM(withdrawal_set);
        return true;
    }
    else {
        std::cout << "\n\t\tThis transaction isn't available\n";
    }
    return false;
}

int main() {
    std::fill(withdrawal_set.begin(), withdrawal_set.end(), 0);
    std::fill(atm_cash.begin(), atm_cash.end(), 0);
    std::string enter_str = enter("\nEnter '+' for Encashment!\nEnter '-' for Client!");
    if (enter_str == "+") {
        processEncashment();
    }
    else if (enter_str == "-") {
        processClient();
        withdrawal();
    }
    else if (enter_str == "!") {
        processClient();
        printATM(atm_cash);
    }
    std::cout << "\n\n\t\t\t!Good Bye!" << std::endl;
    return 0;
}
