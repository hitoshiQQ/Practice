#include "Source.h"
/*
*   100 - Data entry error code
*/

int main() {

    cout << "\t\tBull's && Cow's\n\n";

    std::string num, secretNum;
    int bull{ 0 }, cow{ 0 };

    cout << "Enter the number  to guess: ";
    cin >> secretNum;

    cout << "Enter your number: ";
    cin >> num;

    if (cin.fail() || secretNum.length() != 4 || num.length() != 4 )
    {
        std::cerr << "Error\n";
        return 100;

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
 
    int countSameNum{ 0 }, countSameSecretNum{ 0 };
    
    for (int j = 0; j < num.length(); ++j) {
        if (num[j] == num[j + 1]) {
            countSameNum++;
        }
        if (secretNum[j] == secretNum[j + 1]) {
            countSameSecretNum++;
        }
        
        for (int i = 0; i < num.length(); ++i) {
            if (num[j] == secretNum[i]) {
                if (j == i) { bull++; }
                else { cow++; }

            }
        }
    }
    cow -= countSameNum;
    cow -= countSameSecretNum;

    if (bull == 4) {
        cout << "U guessed all the number's!!!";
        return 0;
    }
    else {
        cout << "\n\nBull's: " << bull;
        cout << "\nCow's: " << cow;
    }

    
    return 0;
}