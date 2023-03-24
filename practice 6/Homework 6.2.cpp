#include "Source.h"

int main()
{
    cout << "\t\tThe numbers are too big\n\n";

    int number;
    cout << "Enter number: "; cin >> number;

    int counter{ 0 };
    bool flag = number < INT_MAX;
    bool zero = number == 0;

    while (number!= 0) {
        ++counter;
        number /= 10;    
    }

    if ( number==0 && flag  && !zero )
        cout << "Number of digits in a number: " << counter;
    else if(zero)
        cout <<"Number of digits in a number: " << ++counter;
    else 
        cout << "Number are too big!";

    return 0; 
}