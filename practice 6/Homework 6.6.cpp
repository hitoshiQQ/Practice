#include "Source.h"

int main()
{
    cout << "\t\tDeposits\n\n";
    int depositSum, interestRate, needSum, year{ 0 };

    cout << "Enter the deposit amount: "; cin >> depositSum;
    cout << "Enter the interest rate : ";  cin >> interestRate;
    cout << "Enter the desired amount: "; cin >> needSum;

   
    while (depositSum < needSum) {

        depositSum += depositSum / interestRate;
        ++year;
    }
    cout <<"Need to wait            : "<< year<<" year's";

    return 0;
}