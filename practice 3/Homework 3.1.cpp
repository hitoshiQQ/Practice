#include "Source.h"

int main(){
    
    cout << "\t\tMINorMAX Number's\n";

    int firstNum;
    int secondNum;

    cout << "Enter first number: ";
    cin >> firstNum;

    cout << "Enter second number: ";
    cin >> secondNum;

    firstNum > secondNum ? cout << "First number is a bigger!\n"
        : firstNum == secondNum ? cout << "Numbers are equal!\n" 
        : cout << "Second number is a bogger!\n";

    return 0;
}

