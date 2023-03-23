#include "Source.h"

int main()
{
    cout << "\t\tMay\n\n";

    int day;
    cout << "Enter the day of May: "; cin >> day;

    if (day < 1 && day>31)
        cout << "Wrong";

    if (day >= 1 && day <= 5 || day >= 8 && day <= 10)
        cout << "Holiday weekend!";
    else if ((day + 1) % 7 == 0 || day % 7 == 0)
        cout << "Holiday!";
    else
        cout << "Weekday";

    return 0;
}