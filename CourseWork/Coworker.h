#pragma once
#include <string>
#include "Osoba.h"
#include <cctype>

class Coworker : public Osoba
{
private:
	int tableNumber;
	double salary;
	double experience;
	double hoursWorked;
	double salaryPerHour;

public:

	Coworker();

	Coworker(string surname, string name, string middleName, string birthDate, string gender,
		int tableNumber, double salary, double experience, double hoursWorked, double salaryPerHour);

	// ����������� ���������
	Coworker(const Coworker& other) {
		tableNumber = other.tableNumber;
		salary = other.salary;
		experience = other.experience;
		hoursWorked = other.hoursWorked;
		salaryPerHour = other.salaryPerHour;
	}

	~Coworker() {}

	virtual std::string printPersonInfo() override;

	// ������� ��� ����� Coworker
	void SetTableNumber(int tableNumber);
	void SetSalary(double salary);
	void SetExperience(double experience);
	void SetHoursWorked(double hoursWorked);
	void SetSalaryPerHour(double salaryPerHour);

	// ������� ��� ����� Coworker
	int GetTableNumber();
	double GetSalary();
	double GetExperience();
	double GetHoursWorked();
	double GetSalaryPerHour();

	// �������������� ��������� �������� �� ������ �����
	friend std::istream& operator>>(std::istream& is, Coworker& coworker);
	friend std::ostream& operator<<(std::ostream& os, Coworker& coworker);

	// ³�������� ������� ������� ���������� ������ �����������
	virtual std::string GetPersonData();
};