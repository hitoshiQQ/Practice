#include "Source.h"

/*
*   100 - Data entry error code
*/

int main() {

    cout << "\t\tImmolate Improved!\n\n";

    float health, magicResist;
    float damage, fireballPower;

    cout << "Enter health: ";
    cin >> health;

    cout << "Enter magic resistance: ";
    cin >> magicResist;

    if (cin.fail() || cin.peek() != '\n'|| health>1 
        || health <= 0 || magicResist>1||magicResist<=0 )
    {
        std::cerr << "\n\t\t!Input Error!\n";
        return 100;

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }


    while (health > 0.f) {
        cout << "\nEnter power of the fireball: ";
        cin >> fireballPower;

        if (cin.fail() || cin.peek() != '\n'|| fireballPower >1 || fireballPower<0) {
            std::cerr << "\n\t\t!Input Error!\n";
            return 100;

            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        damage = fireballPower - magicResist;

        if (damage < 0.f) {
            damage = 0.f;
        }
         
        health -= damage;

        cout << "\n============================";
        cout << "\nDamage = " << damage;
        cout << "\nHealth Orc = " << health;
        cout << "\n============================";
    }

    return 0;
}