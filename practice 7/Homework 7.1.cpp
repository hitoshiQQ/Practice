#include "Source.h"

int main()
{
    cout << "\t\tFood stocks\n\n";

    int buckwheatMass{ 100 },month;
    
    
    
    for (month = 0; buckwheatMass > 0; ++month,buckwheatMass-=4) {

        if (buckwheatMass == 100) {
            cout << "The total buckwheat was at the beginning of the count: "
                << buckwheatMass;
            continue;
        }

        if (buckwheatMass <= 0) {
            cout << "\nAfter " << month << " month buckwheat ran out!";
            break;
        }

        cout << "\n\tAfter " << month << " month, will have "
             << buckwheatMass << " kg buckwheat in reserve";     
    }
    
    return 0;
}