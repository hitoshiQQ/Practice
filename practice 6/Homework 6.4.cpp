#include "Source.h"

int main()
{
    cout << "\t\tHappy ticket\n\n";

    int num, one_digit{ 0 }, two_digit{ 0 };

    cout << "Enter ticket number: ";
    cin >> num;
   
    bool check = num / 100000 >= 1;

    for (int j = 0; j < 3; ++j) {
        one_digit += num % 10;
        num /= 10;
    }
    for (int j = 0; j < 3; ++j) {
        two_digit += num % 10;
        num /= 10;
    }

    if (check == false)
        cout << "Wrong number";
    else if (one_digit == two_digit)
        cout << "Happy ticket";
    else
        cout << "Unhappy ticket";

   
    return 0;
}