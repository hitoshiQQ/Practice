#include "Source.h"

int main()
{
    cout << "\t\tMilitary paramedic\n";
    int alcohol, aidKit;

    cout << "Enter alcohol volume | number of first aid kit's: ";
    cin >> alcohol >> aidKit;

    if (alcohol >= 2000 || aidKit >= 5)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}

