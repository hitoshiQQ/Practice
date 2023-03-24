#include "Source.h"

int main()
{
    cout << "\t\tReduction of fractions\n\n";

    int nom, denom,commonDenom;;
   
    cout << "Enter the numerator  : "; cin >> nom;
    cout << "Enter the denominator: "; cin >> denom;

    bool nomFlag = nom > 0;
    bool denomFlag = denom > 0;

    nom = abs(nom); denom = abs(denom);

    if (nom < denom)
        commonDenom = nom;
    else
        commonDenom = denom;

    for (; commonDenom > 0; --commonDenom) {

        if (nom % commonDenom == 0
            && denom % commonDenom == 0) {
            nom /= commonDenom;
            denom /= commonDenom;
        }
    }

    if (nomFlag == false) 
        nom *= -1;
    if (denomFlag == false)
        denom *= -1;
    

    cout << nom << "/" << denom;

  
    return 0;
}