#include "Source.h"

int main()
{
    cout << "\t\tCoordinate axes\n\n";

    for (int x = 0; x <= 20; ++x) {
        for (int y = 0; y <= 50; ++y) {
            if (x == 10 && y == 25)
                cout << "+";
            if (y == 50 && x == 10)
                cout << ">";
            if (x == 0 && y == 25)
                cout << "^";

            if (x == 10 && y < 50)
                cout << "-";
            else if (y == 25 && x > 0)
                cout << "|";
            else
                cout << " ";
        }
        std::cout << "\n";
    }
   
    return 0;
}