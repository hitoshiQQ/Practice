#include "Source.h"

int main(){

    cout << "\t\tMental addition\n";

    int firstNum;
    int secondNum;
    int result;

    cout << "\nEnter first number: ";
    cin >> firstNum;

    cout << "\nEnter second number: ";
    cin >> secondNum;

    cout << "\nEnter the sum of the numbers: ";
    cin >> result;
    cout << "-------------check-------------\n";

    result == firstNum + secondNum ? cout << "Right!\n"
        : cout << "Wrong! Right result: " << firstNum + secondNum;

    return 0;
}