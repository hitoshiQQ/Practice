#include "Source.h"

int main() {

    cout << "\t\tMultiplicity of a number\n";

    int firstNum;
    int secondNum;

    cout << "Enter first number: ";
    cin >> firstNum;

    cout << "Enter second number: ";
    cin >> secondNum;

    firstNum% secondNum == 0 ? cout << "Yes, " << firstNum << " is divisible by "
        << secondNum << " without a remainder!\n"
                              :cout << "No, " << firstNum <<  " isn't divisible by "
        << secondNum << " without a remainder!\n";

    return 0;
}