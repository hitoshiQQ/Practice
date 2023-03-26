#include "Source.h"

/*
*   100 - Data entry error code
*/

int main() {

	cout << "\t\tSpace Simulator\n\n";

	float mass, traction, time;
    
    cout << "\nEnter mass: ";
    cin >> mass;

    cout << "Enter traction: ";
    cin >> traction;

    cout << "Enter time in second's: ";
    cin >> time;
   
    if (cin.fail() || cin.peek() != '\n')
    {
        std::cerr << "\n\t\t!Input Error!\n";
        return 100;

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    float a = traction / mass;
    float result = (a * pow(time, 2)) / 2;

    cout << "\nThe ship will go the distance: " << result;

    return 0; 
}