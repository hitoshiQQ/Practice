#include "Source.h"

/*
*   100 - Data entry error code
*/

int main() {

    cout << "\t\tKenyan runner\n\n";
    int countKilometer, time{ 0 };
    cout << "Enter the number of kilometers: ";
    cin >> countKilometer;

    for (int tempKilometer = 1; tempKilometer <= countKilometer; ++tempKilometer) {

        int tempTime;
        cout << "Enter the time per kilometer " << tempKilometer << ": ";
        cin >> tempTime;

        time += tempTime;
    } 
  
    if (cin.fail() || cin.peek() != '\n')
    {
        std::cerr << "\n\n\t\tError\n";
        return 100;

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    int averageTime = round((float)time / (float)countKilometer);
   
    int minute, second;
    minute = averageTime / 60;
    second = averageTime % 60;

    cout << "\nYour average tempo: " << minute << " minute's  " 
        << second << " second's!";

    return 0;
}