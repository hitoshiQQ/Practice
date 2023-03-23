#include "Source.h"

int main()
{
    cout << "\t\tUpgrade May\n\n";

    int day,dayWeek;
    cout << "Enter the day of May: ";  cin >> day;
    cout << "Enter the start day of the week: "; cin >> dayWeek;

    if (day < 1 || day>31 || dayWeek < 1 || dayWeek > 7) {
        cout << "Wrong";
        return 0;
    }
        
    if (day >= 1 && day <= 5 || day >= 8 && day <= 10)
        cout << "Holiday weekend!";
    else if ((day + dayWeek) % 7 <= 1)
        cout << "Holiday!";
    else
        cout << "Weekday";

    return 0;
}