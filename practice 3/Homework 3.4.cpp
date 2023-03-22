#include "Source.h"

int main() {

    cout << "\t\tExperience Calculation \n";

    int exp;

    cout << "Enter number of experience: ";
    cin >> exp;
    cout << "-------------check-------------\n";

    if (exp >= 5000) {
        cout << "Your level = 4\n";
    }
    else if (exp >= 2500 && exp < 5000) {
        cout << "Your level = 3\n";
    }
    else if (exp >= 1000 && exp < 2500) {
        cout << "Your level = 2\n";
    }
    else if (exp < 1000 && exp > 0) {
        cout << "Your level = 1\n";
    }
    else {
        cout << "Wrong!";
    }

    return 0;
}