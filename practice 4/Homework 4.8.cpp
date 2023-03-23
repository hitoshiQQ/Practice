#include "Source.h"

int main(){

    cout << "\t\tSad Growing Up\n";

    int day, month, year, dayCurrent, monthCurrent, yearCurrent;

    cout << "Enter the day month and year of your birth: ";
    cin >> day >> month >> year;

    cout << "Enter the day month and year today: ";
    cin >> dayCurrent >> monthCurrent >> yearCurrent;


    if (yearCurrent - year > 18)
        cout << "Yes";
    else if (yearCurrent - year == 18 && monthCurrent > month)
        cout << "Yes";
    else if (monthCurrent == month && dayCurrent > day && yearCurrent - year == 18)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}