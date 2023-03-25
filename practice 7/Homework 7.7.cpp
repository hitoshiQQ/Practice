#include "Source.h"

int main()
{
   cout << "\t\tBiolaboratory\n\n";

   int countBacteria, countAntibiotic;
   
   int hour{ 1 };

   cout << "Enter the amount of bacteria  : "; cin >> countBacteria;
   cout << "Enter the amount of antibiotic: "; cin >> countAntibiotic;
   
   
   countAntibiotic *= 10;
   for (; countBacteria > 0 && countAntibiotic > 0; ++hour) {
	   countBacteria *= 2;
	   countBacteria -= countAntibiotic;

	   if (countBacteria <= 0) {
		   cout << "\n\nAll the bacteria have died!";
		   break;
	   }

	   cout << "After " << hour << " hour, bacteria remained: " << countBacteria<<endl;
	   --countAntibiotic;
   }
   cout << "\n\n\nThe effects of the antibiotic ended, the bacteria survived\n";
   

   return 0;
}