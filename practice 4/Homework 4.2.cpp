#include "Source.h"

int main()
{
    cout << "\t\tFlight is fine\n\n";
    
    int speed, height;
    cout << "Enter speed | height: "; cin >> speed >> height;

    if ((speed >= 750 && speed <= 850)
        && (height >= 9000 && height <= 9500))
        cout << "Right";
    else
        cout << "Wrong";

    return 0;
}