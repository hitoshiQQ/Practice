#include "Source.h"

int main()
{
    cout << "\t\tATM-2\n\n";

    int n;
    cout << "Enter amount money: "; cin >> n;

    if (n > 150000) {
        cout << "Incorrect amount entered\n";
        return -1;
    }

    cout << "\n\n=============================================\n";
    if (n >= 5000 ) {
        cout << "5000 denomination bills: " << n / 5000 << endl;
        n %= 5000;
    }
    if (n >= 2000) {
        cout << "2000 denomination bills: " << n / 2000 << endl;
        n %= 2000;
    }
    if (n >= 1000) {
        cout << "1000 denomination bills: " << n / 1000 << endl;
        n %= 1000;
    }
    if(n >= 500) {
        cout << "500  denomination bills: " << n / 500 << endl;
        n %= 500;
    }
    if (n >= 200) {
        cout << "200  denomination bills: " << n / 200 << endl;
        n %= 200;
    }
    if (n >= 100) {
        cout << "100  denomination bills: " << n / 100 << endl;
        n %= 100;
    }
    else
        cout << "It is not possible to issue this amount!\n";


    return 0;
}