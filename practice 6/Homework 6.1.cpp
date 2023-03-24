#include "Source.h"

int main()
{
    cout << "\t\tCuckoo\n\n";
    
    int answer;
    cout << "Enter what time it is: "; cin >> answer;

    bool flag = answer > 0 && answer < 24;
    int iter{ 0 };

    while (flag&&iter<answer) {
        cout << "\nCoo-Coo!";
        ++iter;
    }

    return 0;
}