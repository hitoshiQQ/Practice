#include "Source.h"

int main()
{
    cout << "\t\tRed Mars\n\n";
    
    int x{ 7 }, y{ 10 };
    char command;

    while (true) {

        cout << "[Program]: The rover is at position " << x << ", "
            << y << ", " << "enter command : ";
        cout << "\n[Operator]: "; cin >> command;
        
        if (command == 'A') {

            if (x == 1) {
                cout << "\n\t\tWrong move!!!\n\n";
                continue;
            }else
                --x;

        }else if (command == 'D') {

            if (x == 15) {
                cout << "\n\t\tWrong move!!!\n\n";
                continue;
            }
            else
                ++x;

        }else if (command == 'W') {

            if (y == 20) {
                cout << "\n\t\tWrong move!!!\n\n";
                continue;
            }
            else
                ++y;

        }else if (command == 'S') {

            if (y == 1) {
                cout << "\n\t\tWrong move!!!\n\n";
                continue;
            }
            else
                --y;
        }else {
            cout << "\n\n\t\tUnkown command!\n\n";
            continue;
        }     
    }

    return 0;
}