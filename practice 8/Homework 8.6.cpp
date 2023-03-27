#include "Source.h"

/*
*   100 - Data entry error code
*/

int main() {

    cout << "\t\tPendulum\n\n";
    float fluctStart, fluctEnd;
    cout << "Enter the initial amplitude of oscillations: ";
    cin >> fluctStart;
    cout << "Enter the amplitude of the stopping oscillation: ";
    cin >> fluctEnd;

    if (cin.fail() || cin.peek() != '\n'|| fluctEnd>fluctStart)
    {
        std::cerr << "\n\n\t\tError\n";
        return 100;

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    int count{ 0 };

    while (fluctStart > fluctEnd) {
        ++count;
        fluctStart *= 1 - (8.4f / 100.f);
    }
    cout << count;

    return 0;
}