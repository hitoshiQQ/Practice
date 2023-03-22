#include "Source.h"

int main() {

    setlocale(LC_ALL, "ru");
    int mansCount;
    int barbersCount;

    std::cout << "************** Барбершоп-калькулятор **************\n";
    std::cout << "Введите число мужчин в городе: ";
    std::cin >> mansCount;

    std::cout << "Сколько уже барберов удалось нанять?";
    std::cin >> barbersCount;

    // Сколько человек нужно постричь за день?
    int mansPerDay = mansCount / 30;

    // Сколько человек может постричь один барбер за одну смену?
    int mansPerBarber = 8;                           // Обслужит столько человек 1 барбер
    int barberPerDay = mansPerBarber * barbersCount; // Обслужит барбершоп в день
   

    // Соотношение Возможность обслужить к кол-ву клиентов
    if (barberPerDay % mansPerDay>=8) {
        cout << "Барберов недостаточно";
    }
    else if(barberPerDay==mansPerDay && barberPerDay % mansPerDay==0) {
        if (mansCount % 30 == 0) {
            cout << "Барберов хватает идеально!!!\n";
        }
        else {
            cout << "Барберов недостаточно";
        }  
    }
    else {
        cout << "Барберов хватает!!!\n";
    }

}
 