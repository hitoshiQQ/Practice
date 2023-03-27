#include "Source.h"

/*
*   100 - Data entry error code
*/


int main() {

    cout << "\t\tBiolaboratory 2.0 Upgrade\n\n";

    int countBacteriaOld;
    float countAntibiotic, countWater;

    cout << "Enter start the amount of bacteria  : "; cin >> countBacteriaOld;
    cout << "Enter the amount of antibiotic: "; cin >> countAntibiotic;
    cout << "Enter ammount of water: "; cin >> countWater;

    if (cin.fail() || cin.peek() != '\n'|| countBacteriaOld < 0 
        || countAntibiotic< 0.f || countWater <0.f)
    {
        std::cerr << "\n\n\t\tError\n";
        return 100;

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    int minute{ 1 };
    for (float antibiotic = countAntibiotic; minute!=21; ++minute) {

        float concentration = antibiotic / countWater;
        float countBacteriaNew = floor(2 * countBacteriaOld - countBacteriaOld * concentration);
       
        

        if (countBacteriaNew <= 0&& minute > 1) {
            cout << "\n\nAll the bacteria have died!";
            break;
        }
        else if (antibiotic <= 0) {
            cout << "\n\nAll antibiotic ran out!";
            break;
        }
        cout << "After " << minute << " minute's, bacteria remained: " << countBacteriaNew << endl;
        cout << "\tConcentration : " << concentration << endl<<endl;

        antibiotic *= 0.8f;
        countBacteriaOld = countBacteriaNew;
    }


    return 0;
}