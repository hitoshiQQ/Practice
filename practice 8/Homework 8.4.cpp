#include "Source.h"

/*
*   100 - Data entry error code
*/

int main() {

    cout << "\t\tSteam killer\n\n";

    float fileSize, internetSpeed;

    cout << "Enter the file size: "; cin >> fileSize;
    cout << "Enter the internet speed: "; cin >> internetSpeed;
  
    if (cin.fail() || cin.peek() != '\n')
    {
        std::cerr << "\n\n\t\tError\n";
        return 100;

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    int sec{ 1 }, procent{ 0 };
    for (float j = internetSpeed; procent<100 ; j += internetSpeed,++sec) {
        if (j >= fileSize)
            j = fileSize;

        procent = floor((j / fileSize * 100));
        cout << "Gone " << sec << " sec. Download " << j
            << " from " << fileSize << " Mb (" <<procent<< "%)\n";
      
    }

    return 0;
}