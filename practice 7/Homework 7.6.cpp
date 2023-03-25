#include "Source.h"

int main()
{
    cout << "\t\tImportant announcements\n\n";

    int len, count;
    cout << "Enter the total length of the footer's  : "; cin >> len;
    cout << "Enter the number of exclamation point's : "; cin >> count;

    if (len >= count) {
        for (int j = 0; j < (len - count) / 2; ++j) {
            cout << "~";
        }
        for (int j = 0; j < count; ++j) {
            std::cout << "!";
        }
        if (count % 2 == 0) {
            for (int j = 0; j < ((len - count) / 2) + (len % 2 != 0); ++j) {
                std::cout << "~";
            }
        } else {
            for (int j = 0; j < ((len - count) / 2) + (len % 2 == 0); ++j) {
                std::cout << "~";
            }
        }
        
    }

    return 0;
}