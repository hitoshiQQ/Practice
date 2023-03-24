#include "Source.h"

int main()
{
    cout << "\t\tBank collectors\n\n";

    int debtSum,  sum{ 0 };
    std::string debtName;
    cout << "Enter the amount of debt: "; cin >> debtSum;
    cout << "Enter the debtor's name: "; cin >> debtName;

    bool debt_repaid = debtSum<0;
    
    while (debtSum>0) {
        
        cout <<endl<< debtName << ", repay the debt in the amount of: "<<debtSum;
        cout << "\nEnter your pay: ";
        cin >> sum;
        debtSum -= sum;
    }

    if (!debt_repaid)
        cout << "\nDebt repaid! Your account balance :" << abs(debtSum);
    else
        cout << "\nDebt repaid";

    return 0;
}