#include "Source.h"

int main() {

    setlocale(LC_ALL, "ru");
    int mansCount;
    int barbersCount;

    std::cout << "************** ���������-����������� **************\n";
    std::cout << "������� ����� ������ � ������: ";
    std::cin >> mansCount;

    std::cout << "������� ��� �������� ������� ������?";
    std::cin >> barbersCount;

    // ������� ������� ����� �������� �� ����?
    int mansPerDay = mansCount / 30;

    // ������� ������� ����� �������� ���� ������ �� ���� �����?
    int mansPerBarber = 8;                           // �������� ������� ������� 1 ������
    int barberPerDay = mansPerBarber * barbersCount; // �������� ��������� � ����
   

    // ����������� ����������� ��������� � ���-�� ��������
    if (barberPerDay % mansPerDay>=8) {
        cout << "�������� ������������";
    }
    else if(barberPerDay==mansPerDay && barberPerDay % mansPerDay==0) {
        if (mansCount % 30 == 0) {
            cout << "�������� ������� ��������!!!\n";
        }
        else {
            cout << "�������� ������������";
        }  
    }
    else {
        cout << "�������� �������!!!\n";
    }

}
 