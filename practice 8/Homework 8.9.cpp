#include "Source.h"

/*
*   100 - Data entry error code
*   101 - Incorrect data entry
*/


int main() {

    cout << "\t\tEgg's\n\n";
    
    float maxDanger;
    float depth_from{ 0 }, depth_to{ 4 };

    cout << "Enter the depth of the masonry in meters: ";
    cin >> maxDanger;

    if (cin.fail() || cin.peek() != '\n')
    {
        std::cerr << "\n\n\t\tError\n"; 
        return 100;

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    float depth = depth_from + (depth_to - depth_from) / 2.f;
    float danger = pow(depth, 3) - (3 * pow(depth, 2)) - (12 * depth) + 10;

    if (maxDanger <= 0) {
        cout << "\nWrong input max danger!";
        return 101;
    }else {
        while (abs(danger) > maxDanger) {
            if (danger > 0)
                depth_from = depth;
            else
                depth_to = depth;
            depth = depth_from + (depth_to - depth_from) / 2.f;
            danger = pow(depth, 3) - (3 * pow(depth, 2)) - (12 * depth) + 10;
        }
    }
    cout <<"Approximate depth of safe masonry: " << depth;


    return 0;
}