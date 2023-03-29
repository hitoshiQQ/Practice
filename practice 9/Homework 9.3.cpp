#include "Source.h"

int main() {

	cout << "\t\tWord count\n\n";

    char text[100];
    int count{ 0 }, j{ 0 }; bool word = false;
    
    cout << "Enter text: " << endl;
    cin.get(text, 100);
    
    while (text[j] == ' ' && text[j] != '\0')
        ++j;
    word = false;


    while (text[j] != '\0') {
        if (text[j] != ' ' && !word )
        {
            word = true;
            ++count;
        }
        else if (text[j] == ' ')
            word = false;
        ++j;
    }

    cout << "Count word's in the text: " << count;
    
   

	return 0;
}