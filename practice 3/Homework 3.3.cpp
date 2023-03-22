#include "Source.h"

int main() {

    cout << "\t\tEven number check\n";

    int num;

    cout << "\nEnter first number: ";
    cin >> num;
    cout << "-------------check-------------\n";

    num % 2 == 0 ? cout << "Number " << num << " - is Even\n"
        : cout << "Number " << num << " - is Odd\n";

    return 0;
}