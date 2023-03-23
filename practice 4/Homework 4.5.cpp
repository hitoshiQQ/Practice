#include "Source.h"

int main()
{
    setlocale(LC_ALL, "ru");

    cout << "\t\tDeclension of Russian words\n\n";

    int num;
    cout << "Enter the number: "; cin >> num;

    if (num < 0) {
        cout << "Error\n";
        return -1;
    }

    if ((num % 100) >= 11 && (num % 100) <= 19)
        cout << num << " рублей\n";
    else
        switch (num % 10) {
        case 1:
            cout << num << " рубль\n";
            break;
        case 2: case 3: case 4: 
            cout << num << " рубля\n";
            break;

        default: cout << num << " рублей\n";
        }

    return 0;
}