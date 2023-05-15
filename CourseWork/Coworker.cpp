#include "Coworker.h"
#include "Osoba.h"
#include <string>
#include <iostream>
#include <cctype>

using namespace std;

Coworker::Coworker()
{
	tableNumber = 0;
	salary = 0.0;
	experience = 0;
	hoursWorked = 0.0;
	salaryPerHour = 0.0;
}

Coworker::Coworker(string surname, string name, string middleName, string birthDate, string gender, int tableNumber, double salary, double experience, double hoursWorked, double salaryPerHour)
: Osoba(surname, name, middleName, birthDate, gender)
{
	if (tableNumber < 0)
		throw("Табельний номер не може бути від'ємним");
	this->tableNumber = tableNumber;
	if (salary < 0)
		throw("Оклад не може бути від'ємною");
	this->salary = salary;
	if (experience < 0)
		throw("Досвід не може бути від'ємним");
	this->experience = experience;
	if (hoursWorked < 0)
		throw("Кількість віпрацьованих годин не можуть бути від'ємними");
	this->hoursWorked = hoursWorked;
	if (salaryPerHour < 0)
		throw("ЗП/год не може бути від'ємним значенням");
	this->salaryPerHour = salaryPerHour;
}


std::string Coworker::printPersonInfo()
{
	string personInfo = surname + " " + name + " " + middleName + "\n";
	personInfo += "Дата народження: " + birthDate + "\n";
	personInfo += "Стать: '" + gender + "'\n";
	personInfo += "Табельний номер: " + std::to_string(tableNumber) + "\n";
	personInfo += "Оклад: " + std::to_string(salary).substr(0, std::to_string(salary).find('.') + 3) + "\n"; // скорочуємо до двох знаків після коми
	personInfo += "Стаж роботи: " + std::to_string(experience).substr(0, std::to_string(experience).find('.') + 2) + "\n";
	personInfo += "Кількість відпрацьованих годин: " + std::to_string(hoursWorked).substr(0, std::to_string(hoursWorked).find('.') + 3) + "\n";
	personInfo += "Зарплата за годину роботи: " + std::to_string(salaryPerHour).substr(0, std::to_string(salaryPerHour).find('.') + 3) + "\n"; // скорочуємо до двох знаків після коми
	return personInfo;
}


void Coworker::SetTableNumber(int tableNumber)
{
	if (tableNumber < 0)
		throw("Табельний номер не може бути від'ємним");
	this->tableNumber = tableNumber;
}

void Coworker::SetSalary(double salary)
{
	if (salary < 0)
		throw("Оклад не може бути від'ємною");
	this->salary = salary;
}

void Coworker::SetExperience(double experience)
{
	if (experience < 0)
		throw("Досвід не може бути від'ємним");
	this->experience = experience;
}

void Coworker::SetHoursWorked(double hoursWorked)
{
	if (hoursWorked < 0)
		throw("Кількість віпрацьованих годин не можуть бути від'ємними");
	this->hoursWorked = hoursWorked;
}

void Coworker::SetSalaryPerHour(double salaryPerHour)
{
	if (salaryPerHour < 0)
		throw("ЗП/год не може бути від'ємним значенням");
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
	if (coworker.tableNumber < 0)
		throw("Табельний номер не може бути від'ємним");
	is >> coworker.tableNumber;
	cout << "Оклад: ";
	if (coworker.salary < 0)
		throw("Оклад не може бути від'ємною");
	is >> coworker.salary;
	cout << "Досвід роботи: ";
	if (coworker.experience < 0)
		throw("Досвід не може бути від'ємним");
	is >> coworker.experience;
	cout << "Кількість відпрацьованих годин: ";
	if (coworker.hoursWorked < 0)
		throw("Кількість віпрацьованих годин не можуть бути від'ємними");
	is >> coworker.hoursWorked;
	cout << "Зарплата за годину роботи: ";
	if (coworker.salaryPerHour < 0)
		throw("ЗП/год не може бути від'ємним значенням");
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
