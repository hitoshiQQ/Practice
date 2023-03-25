#include "Source.h"

int main()
{
    cout << "\t\tCoffee machine\n\n";

    int water, milk, choise, countLatte{0}, countAmericano{0};

    cout << "Enter the volume of water: "; cin >> water;
    cout << "Enter the volume of milk: ";  cin >> milk;

    while (water >= 300 ||water >= 30 && milk >= 270) {

        cout << "\n\n\t\t\tWelcome, choose your coffee!\n";
        cout << "\t\tChoise a drink 1 - Americano || 2 - Latte : "; cin >> choise;

        if (choise == 1) {
            if (water < 300) {
                cout << "\nNot enough water";
            }else {
                cout << "\nYour drink is ready";
                water -= 300;
                ++countAmericano;
            }   
        }

        if (choise == 2) {
            if (water < 30) {
                cout << "\nNot enough water";
            }else if (milk < 270) {
                cout << "\nNot enough milk";
            }else {
                cout << "\nYour drink is ready";
                water -= 30; milk -= 270;
                ++countLatte;
            }
        }
    }

    cout << "\n\n\t\t\t***Report***\n";
    cout << "\t\tIngredients left over: \n";
    cout << "\t\t\t Water : " << water << endl;
    cout << "\t\t\t Milk : " << milk << endl;
    cout << "\t\tAmericano mugs made: " << countAmericano<<endl;
    cout << "\t\tLatte mugs made: " << countLatte<<endl;
    
 

    return 0;
}