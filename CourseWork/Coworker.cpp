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
		throw("��������� ����� �� ���� ���� ��'�����");
	this->tableNumber = tableNumber;
	if (salary < 0)
		throw("����� �� ���� ���� ��'�����");
	this->salary = salary;
	if (experience < 0)
		throw("����� �� ���� ���� ��'�����");
	this->experience = experience;
	if (hoursWorked < 0)
		throw("ʳ������ ������������ ����� �� ������ ���� ��'������");
	this->hoursWorked = hoursWorked;
	if (salaryPerHour < 0)
		throw("��/��� �� ���� ���� ��'����� ���������");
	this->salaryPerHour = salaryPerHour;
}


std::string Coworker::printPersonInfo()
{
	string personInfo = surname + " " + name + " " + middleName + "\n";
	personInfo += "���� ����������: " + birthDate + "\n";
	personInfo += "�����: '" + gender + "'\n";
	personInfo += "��������� �����: " + std::to_string(tableNumber) + "\n";
	personInfo += "�����: " + std::to_string(salary).substr(0, std::to_string(salary).find('.') + 3) + "\n"; // ��������� �� ���� ����� ���� ����
	personInfo += "���� ������: " + std::to_string(experience).substr(0, std::to_string(experience).find('.') + 2) + "\n";
	personInfo += "ʳ������ ������������� �����: " + std::to_string(hoursWorked).substr(0, std::to_string(hoursWorked).find('.') + 3) + "\n";
	personInfo += "�������� �� ������ ������: " + std::to_string(salaryPerHour).substr(0, std::to_string(salaryPerHour).find('.') + 3) + "\n"; // ��������� �� ���� ����� ���� ����
	return personInfo;
}


void Coworker::SetTableNumber(int tableNumber)
{
	if (tableNumber < 0)
		throw("��������� ����� �� ���� ���� ��'�����");
	this->tableNumber = tableNumber;
}

void Coworker::SetSalary(double salary)
{
	if (salary < 0)
		throw("����� �� ���� ���� ��'�����");
	this->salary = salary;
}

void Coworker::SetExperience(double experience)
{
	if (experience < 0)
		throw("����� �� ���� ���� ��'�����");
	this->experience = experience;
}

void Coworker::SetHoursWorked(double hoursWorked)
{
	if (hoursWorked < 0)
		throw("ʳ������ ������������ ����� �� ������ ���� ��'������");
	this->hoursWorked = hoursWorked;
}

void Coworker::SetSalaryPerHour(double salaryPerHour)
{
	if (salaryPerHour < 0)
		throw("��/��� �� ���� ���� ��'����� ���������");
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
	if (coworker.tableNumber < 0)
		throw("��������� ����� �� ���� ���� ��'�����");
	is >> coworker.tableNumber;
	cout << "�����: ";
	if (coworker.salary < 0)
		throw("����� �� ���� ���� ��'�����");
	is >> coworker.salary;
	cout << "����� ������: ";
	if (coworker.experience < 0)
		throw("����� �� ���� ���� ��'�����");
	is >> coworker.experience;
	cout << "ʳ������ ������������� �����: ";
	if (coworker.hoursWorked < 0)
		throw("ʳ������ ������������ ����� �� ������ ���� ��'������");
	is >> coworker.hoursWorked;
	cout << "�������� �� ������ ������: ";
	if (coworker.salaryPerHour < 0)
		throw("��/��� �� ���� ���� ��'����� ���������");
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
