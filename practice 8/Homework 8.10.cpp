#include "Source.h"

/*
*   100 - Data entry error code
*   101 - Incorrect data entry
*/


int main() {

    cout << "\t\tHard in training, easy in battle\n\n";

    int a, b;

    cout << "Enter first number : "; cin >> a;
    cout << "Enter second number: "; cin >> b;

    if (cin.fail() || cin.peek() != '\n')
    {
        std::cerr << "\n\n\t\tError\n";

        return 100;

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    cout <<"Max number: " << (a + b) / 2.f + abs(a - b) / 2.f;
    
    return 0;
}