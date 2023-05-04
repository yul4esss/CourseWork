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

        // ��������� ���� ��� ���������� ����� ��� �����������
        double salary = coworkersListInfo[i].GetSalary();
        double hoursWorked = coworkersListInfo[i].GetHoursWorked();
        double salaryPerHour = coworkersListInfo[i].GetSalaryPerHour();

        // ������ �� �� ����� + (����������� ������ * ��/���)
        double calculatedSalary = salary + (hoursWorked * salaryPerHour);

        // � �������, �����������, �� �������� ����� 140 �����/�����, 
        // ������ ����� 30% �� ������
        if (hoursWorked > 140) {
            calculatedSalary += 0.3 * salary;
        }

        // ������� �������� �����������
        coworkersListInfo[i].SetSalary(calculatedSalary);
    }
}

std::string Salary::printCoworkersInfo()
{
    std::string result;
    for (int i = 0; i < amountOfCoworkers; i++) {
        double salary = coworkersListInfo[i].GetSalary();
        std::string salaryString = std::to_string(salary);
        salaryString = salaryString.substr(0, salaryString.find('.') + 3); // ������� �� ���� ����� ���� ����
        result += "�������� ����� ���������� � ��������� ������� " + std::to_string(coworkersListInfo[i].GetTableNumber()) + " ������ " + salaryString + "\n";
    }

    return result;
}

