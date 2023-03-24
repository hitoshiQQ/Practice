#include "Source.h"

int main()
{
    cout << "\t\tGuess the number\n\n";

    cout << "Guess a number from 0 to 63 \n";

    int num, left{0}, right{63}, iter{1};
    char answer;

    while (iter < 8) {
        cout << "\n\t\tStep " << iter;
        num = (left + right) / 2;
        cout << "\nYour number is bigger " << num << "? ";
        cout << "\nEnter y / n";
        cin >> answer;

        if (answer == 'y')
            left = num;
        else if (answer == 'n')
            right = num;
        else
            cout << "\nIncorrect input";

        ++iter;
    }

    

    return 0;
}