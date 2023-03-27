#include "Source.h"

/*
*   100 - Data entry error code
*/


int main() {

    cout << "\t\tOcean's Friends\n\n";
    float  timeSec;
    int  countKnob, countPosition,hour,minute, second;

    cout << "Enter count of rotary knobs : ";
    cin >> countKnob;
    cout << "Enter count of position's ";
    cin >> countPosition;
    cout << "Enter seconds to check one combination: ";
    cin >> timeSec;

    if (cin.fail() || cin.peek() != '\n' || timeSec <=0.f )
    {
        std::cerr << "\n\n\t\tError\n";
        return 100;

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    int  count{ 0 };
    count = pow(countPosition, countKnob);
    timeSec *= count;
    
    int allTimeSec = floor(timeSec);

    minute = allTimeSec / 60;
    second = allTimeSec % 60;
    hour = minute / 60;
    minute = minute % 60;

    cout << "\nNeed time to all combination: " <<hour<<" hour's " 
        << minute << " minute's  " << second << " second's!";

    return 0;
}