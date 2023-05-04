#pragma once
#include <string>
#include "Osoba.h"

class Coworker : public Osoba
{
private:
	int tableNumber;
	double salary;
	double experience;
	double hoursWorked;
	double salaryPerHour;

public:

	Coworker() {
		tableNumber = 0;
		salary = 0.0;
		experience = 0;
		hoursWorked = 0.0;
		salaryPerHour = 0.0;
	}

	Coworker(string surname, string name, string middleName, string birthDate, char gender,
		int tableNumber, double salary, double experience, double hoursWorked, double salaryPerHour)
		: Osoba(surname, name, middleName, birthDate, gender) {
		this->tableNumber = tableNumber;
		this->salary = salary;
		this->experience = experience;
		this->hoursWorked = hoursWorked;
		this->salaryPerHour = salaryPerHour;
	}

	// Конструктор копіювання
	Coworker(const Coworker& other) {
		tableNumber = other.tableNumber;
		salary = other.salary;
		experience = other.experience;
		hoursWorked = other.hoursWorked;
		salaryPerHour = other.salaryPerHour;
	}

	~Coworker() {}

	virtual std::string printPersonInfo() override;

	// Сеттери для класу Coworker
	void SetTableNumber(int tableNumber);
	void SetSalary(double salary);
	void SetExperience(double experience);
	void SetHoursWorked(double hoursWorked);
	void SetSalaryPerHour(double salaryPerHour);

	// Геттери для класу Coworker
	int GetTableNumber();
	double GetSalary();
	double GetExperience();
	double GetHoursWorked();
	double GetSalaryPerHour();

	// Перевантаження операторів введення та виводу даних
	friend std::istream& operator>>(std::istream& is, Coworker& coworker);
	friend std::ostream& operator<<(std::ostream& os, Coworker& coworker);

	// Віртуальна функція читання табельного номеру співробітника
	virtual std::string GetPersonData();
};