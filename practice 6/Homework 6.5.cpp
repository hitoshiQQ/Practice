#include "Source.h"

int main()
{
    cout << "\t\tFibonacci numbers\n\n";

    int n, numFib{ 0 };
    cout << "Enter number N: "; cin >> n;

    bool flag = n >= INT_MAX;

    int iter{ 0 }, nextNum{ 1 }, currentNum{ 0 };

    while (iter < n && !flag) {

        nextNum += currentNum;
        currentNum = nextNum-currentNum;

        ++iter;  
    }
    if (flag)
        cout << "\nNumber too big";
    else
        cout << "Your number: " << currentNum;


    return 0;
}