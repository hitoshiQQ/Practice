#include "Source.h"

int main() {

    cout << "\t\tFrom ordinary numbers to Roman \n\n";

    while (true) {
        std::string romanDigit[] = { "M","CM","D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        std::string numRoman;
        int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

        int num;
        cout << "\nEnter the number: "; cin >> num;

        if (cin.fail() || cin.peek() != '\n' || num > 3999 || num < 1)
        {
            std::cerr << "\n\n\t\tError\n";
            return 100;

            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        for (int j = 0; j < 13; ++j) {

            while (num - values[j] >= 0) {

                numRoman += romanDigit[j];
                num -= values[j];
            }
        }

        cout << numRoman;
    }
  
    
    return 0;
}