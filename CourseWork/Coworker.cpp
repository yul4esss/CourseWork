#include "Coworker.h"
#include "Osoba.h"
#include <string>
#include <iostream>

using namespace std;

std::string Coworker::printPersonInfo()
{
	string personInfo = surname + " " + name + " " + middleName + "\n";
	personInfo += "Дата народження: " + birthDate + "\n";
	personInfo += "Стать: '" + std::string(1, gender) + "'\n";
	personInfo += "Табельний номер: " + std::to_string(tableNumber) + "\n";
	personInfo += "Оклад: " + std::to_string(salary).substr(0, std::to_string(salary).find('.') + 3) + "\n"; // скорочуємо до двох знаків після коми
	personInfo += "Стаж роботи: " + std::to_string(experience).substr(0, std::to_string(experience).find('.') + 2) + "\n";
	personInfo += "Кількість відпрацьованих годин: " + std::to_string(hoursWorked).substr(0, std::to_string(hoursWorked).find('.') + 3) + "\n";
	personInfo += "Зарплата за годину роботи: " + std::to_string(salaryPerHour).substr(0, std::to_string(salaryPerHour).find('.') + 3) + "\n"; // скорочуємо до двох знаків після коми
	return personInfo;
}


void Coworker::SetTableNumber(int tableNumber)
{
	this->tableNumber = tableNumber;
}

void Coworker::SetSalary(double salary)
{
	this->salary = salary;
}

void Coworker::SetExperience(double experience)
{
	this->experience = experience;
}

void Coworker::SetHoursWorked(double hoursWorked)
{
	this->hoursWorked = hoursWorked;
}

void Coworker::SetSalaryPerHour(double salaryPerHour)
{
	this->salaryPerHour = salaryPerHour;
}

int Coworker::GetTableNumber()
{
	return tableNumber;
}

double Coworker::GetSalary()
{
	return salary;
}

double Coworker::GetExperience()
{
	return experience;
}

double Coworker::GetHoursWorked()
{
	return hoursWorked;
}

double Coworker::GetSalaryPerHour()
{
	return salaryPerHour;
}

std::string Coworker::GetPersonData()
{
	return std::to_string(tableNumber);
}

std::istream& operator>>(std::istream& is, Coworker& coworker)
{
	// Виклик успадкованих операторів >> для полів класу Osoba, використовуємо статичне приведення до батьківського класу
	is >> static_cast<Osoba&>(coworker);
	// Виклик перевизначеного оператора >> для полів класу Coworker
	cout << "Табличний номер співробітника: ";
	is >> coworker.tableNumber;
	cout << "Оклад: ";
	is >> coworker.salary;
	cout << "Досвід роботи: ";
	is >> coworker.experience;
	cout << "Кількість відпрацьованих годин: ";
	is >> coworker.hoursWorked;
	cout << "Зарплата за годину роботи: ";
	is >> coworker.salaryPerHour;

	return is;
}

std::ostream& operator<<(std::ostream& os, Coworker& coworker)
{
	os << static_cast<Osoba&>(coworker);
	os << "Табельний номер: " << coworker.tableNumber;
	os << "\nОклад: " << coworker.salary;
	os << "\nСтаж роботи: " << coworker.experience;
	os << "\nКількість відпрацьованих годин: " << coworker.hoursWorked;
	os << "\nЗарплата за годину роботи: " << coworker.salaryPerHour;

	return os;
}
