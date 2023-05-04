#include <string>
#include <iostream>
#include "Osoba.h"
#include "Coworker.h"
#include "Salary.h"

using namespace std;

void Salary::addCoworkerToList(Coworker coworker)
{
    coworkersListInfo[amountOfCoworkers] = coworker;
    amountOfCoworkers++;
}

void Salary::calculateSalary()
{
    for (int i = 0; i < amountOfCoworkers; i++) {

        // Створюємо змінні для збереження даних про співробітника
        double salary = coworkersListInfo[i].GetSalary();
        double hoursWorked = coworkersListInfo[i].GetHoursWorked();
        double salaryPerHour = coworkersListInfo[i].GetSalaryPerHour();

        // Рахуємо ЗП як оклад + (відпрацьовані години * зп/год)
        double calculatedSalary = salary + (hoursWorked * salaryPerHour);

        // В додаток, працівникам, які працюють більше 140 годин/місяць, 
        // дається премія 30% від окладу
        if (hoursWorked > 140) {
            calculatedSalary += 0.3 * salary;
        }

        // Оновити зарплату співробітника
        coworkersListInfo[i].SetSalary(calculatedSalary);
    }
}

std::string Salary::printCoworkersInfo()
{
    std::string result;
    for (int i = 0; i < amountOfCoworkers; i++) {
        double salary = coworkersListInfo[i].GetSalary();
        std::string salaryString = std::to_string(salary);
        salaryString = salaryString.substr(0, salaryString.find('.') + 3); // обрізаємо до двох знаків після коми
        result += "Заробітна плата працівника з табельним номером " + std::to_string(coworkersListInfo[i].GetTableNumber()) + " складає " + salaryString + "\n";
    }

    return result;
}

