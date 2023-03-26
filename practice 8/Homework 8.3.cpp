#include "Source.h"

/*
*   100 - Data entry error code
*/

int main() {

    cout << "\t\tToy Story\n\n";

    float x, y, z;
    cout << "Enter the dimensions: "; cin >> x >> y >> z;
    if (cin.fail() || cin.peek() != '\n')
    {
        std::cerr << "Error\n";
        return 100;

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    int _x = floor(x); int _y = floor(y);
    int _z = floor(z);

    // sorting by size
    if (_x < _y)
        std::swap(_x, _y);
    if (_x < _z)
        std::swap(_x, _z);
    if (_y < _z)
        std::swap(_y, _z);

    int set{0}, cube{0}, sizeSet{2};

    if (_z >= 5) {
        _x /= 5; _y /= 5;
        cube = _x * _y;
    }

    
    while (cube > set) {
        ++sizeSet;
        set = pow(sizeSet, 3);
        
    }

    cout <<"Count cube's: " << cube << endl;
    cout <<"Count set's: "  << pow(sizeSet - 1, 3);
    
    return 0;
}