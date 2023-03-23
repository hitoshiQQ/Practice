#include "Source.h"
#include <cmath>

int main() {

    cout << "\t\tTriangle on the coordinate plane\n";

    int x1, y1, x2, y2, x3, y3;
    
    cout << "enter the coordinates of the first point: "; cin >> x1 >> y1;
    cout << "enter the coordinates of the second point: "; cin >> x2 >> y2;
    cout << "enter the coordinates of the third point: "; cin >> x3 >> y3;

    
    if((x2 - x1) * (y3 - y1) == (x3 - x1) * (y2 - y1))
        cout << "Points lie on the same line!\n";
    else
        cout << "points don't lie on the same line!";


    return 0;
}