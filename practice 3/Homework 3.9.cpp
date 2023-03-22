#include "Source.h"

int main() {
    cout << "\t\tTax\n";

    int profit;
    std::cout << "\nEnter your profit : ";
    std::cin >> profit;

    if (profit >= 50000) {
        int tax = ((profit-50000)*30/100)+ ((50000 - 10000) * 20 / 100) + (10000 * 13 / 100);
        std::cout << "Tax - 30%: " << tax << "\n";
    }
    else if (profit >= 10000) {
        int tax = ((profit - 10000)*20/100)+(10000*13/100);
        std::cout << "Tax - 20%: " << tax << "\n";
    }
    else if (profit > 0) {
        int tax = profit * 13 / 100;
        std::cout << "Tax - 13%: " << tax << "\n";
    }
    else {
        std::cout << "Wrong!\n";
    }
 
    return 0;
}