#include "Source.h"

int main()
{
    cout << "\t\tFrame\n\n";
    
    int width, height;
    cout << "Enter the width / height of the frame: ";
    cin >> width >> height;

    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {

            if (i == 0 || i == width - 1)
                cout << "|";
            else if (j == 0 || j == height - 1)
                cout << "-";
            else
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}