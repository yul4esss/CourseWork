#include "Coworker.h"
#include "Osoba.h"
#include <string>
#include <iostream>

using namespace std;

std::string Coworker::printPersonInfo()
{
	string personInfo = surname + " " + name + " " + middleName + "\n";
	personInfo += "���� ����������: " + birthDate + "\n";
	personInfo += "�����: '" + std::string(1, gender) + "'\n";
	personInfo += "��������� �����: " + std::to_string(tableNumber) + "\n";
	personInfo += "�����: " + std::to_string(salary).substr(0, std::to_string(salary).find('.') + 3) + "\n"; // ��������� �� ���� ����� ���� ����
	personInfo += "���� ������: " + std::to_string(experience).substr(0, std::to_string(experience).find('.') + 2) + "\n";
	personInfo += "ʳ������ ������������� �����: " + std::to_string(hoursWorked).substr(0, std::to_string(hoursWorked).find('.') + 3) + "\n";
	personInfo += "�������� �� ������ ������: " + std::to_string(salaryPerHour).substr(0, std::to_string(salaryPerHour).find('.') + 3) + "\n"; // ��������� �� ���� ����� ���� ����
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
	// ������ ������������ ��������� >> ��� ���� ����� Osoba, ������������� �������� ���������� �� ������������ �����
	is >> static_cast<Osoba&>(coworker);
	// ������ ��������������� ��������� >> ��� ���� ����� Coworker
	cout << "��������� ����� �����������: ";
	is >> coworker.tableNumber;
	cout << "�����: ";
	is >> coworker.salary;
	cout << "����� ������: ";
	is >> coworker.experience;
	cout << "ʳ������ ������������� �����: ";
	is >> coworker.hoursWorked;
	cout << "�������� �� ������ ������: ";
	is >> coworker.salaryPerHour;

	return is;
}

std::ostream& operator<<(std::ostream& os, Coworker& coworker)
{
	os << static_cast<Osoba&>(coworker);
	os << "��������� �����: " << coworker.tableNumber;
	os << "\n�����: " << coworker.salary;
	os << "\n���� ������: " << coworker.experience;
	os << "\nʳ������ ������������� �����: " << coworker.hoursWorked;
	os << "\n�������� �� ������ ������: " << coworker.salaryPerHour;

	return os;
}
