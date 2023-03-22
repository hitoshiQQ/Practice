#include "Source.h"

int main() {
    cout << "\t\tSalary differential\n";

    int firstEmployeeSalary;
    int secondEmployeeSalary;
    int thirdEmployeeSalary;

    cout << "Enter salary first employee:  ";
    cin >> firstEmployeeSalary;

    cout << "Enter salary second employee: ";
    cin >> secondEmployeeSalary;

    cout << "Enter salary third employee:  ";
    cin >> thirdEmployeeSalary;

    int Max = (firstEmployeeSalary > secondEmployeeSalary) ? firstEmployeeSalary : secondEmployeeSalary;
    Max = (Max > thirdEmployeeSalary) ? Max : thirdEmployeeSalary;

    int Min = (firstEmployeeSalary < secondEmployeeSalary) ? firstEmployeeSalary : secondEmployeeSalary;
    Min = (Min < thirdEmployeeSalary) ? Min : thirdEmployeeSalary;


    cout << "\n\n--------------------check--------------------\n";
    cout << "\nHigh salary: " << Max;
    cout << "\nThe difference between high and low salary: " << Max - Min;
    cout << "\nAverage salary: "<<(firstEmployeeSalary+ secondEmployeeSalary+ thirdEmployeeSalary) /3.;




    return 0;
}