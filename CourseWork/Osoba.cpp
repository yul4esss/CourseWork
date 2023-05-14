#include "Osoba.h"
#include "CustomException.h"
#include <iostream>
#include <string>


using namespace std;
// ��� ������� �� ��������� ��� ��� �������

// ������� ��� ����� Osoba
void Osoba::SetSurname(string surname)
{
	this->surname = surname;
}

void Osoba::SetName(string name)
{
	this->name = name;
}

void Osoba::SetMiddleName(string middleName)
{
	this->middleName = middleName;
}

void Osoba::SetBirthDate(string birthDate)
{
	this->birthDate = birthDate;
}

void Osoba::SetGender(char gender)
{
	this->gender = gender;
}

// ������� ��� ����� Osoba
string Osoba::GetSurname()
{
	return surname;
}

string Osoba::GetName()
{
	return name;
}

string Osoba::GetMiddleName()
{
	return middleName;
}

string Osoba::GetBirthDate()
{
	return birthDate;
}

char Osoba::GetGender()
{
	return gender;
}

// ���� ���������� ��� �����
std::string Osoba::printPersonInfo()
{
	string personInfo = surname + " " + name + " " + middleName + "\n���� ����������: " + birthDate
		+ "\n�����: '" + std::string(1, gender) + "'";
	return personInfo;
}

// �������������� ()
void Osoba::operator()(std::string surname, std::string name, std::string middleName, std::string birthDate, char gender)
{
	this->surname = surname;
	this->name = name;
	this->middleName = middleName;
	this->birthDate = birthDate;
	this->gender = gender;
}

std::string Osoba::GetPersonData()
{
	return std::string(surname);
}

// �������������� =
Osoba& Osoba::operator=(const Osoba& other)
{

	// �������� �� � ��� ��� �������� � ��'����
	if (this != &other) {
		surname = other.surname;
		name = other.name;
		middleName = other.middleName;
		birthDate = other.birthDate;
		gender = other.gender;
	}

	return *this;
}

// �������������� >>
std::istream& operator>>(std::istream& is, Osoba& osoba)
{
	cout << "�������: ";
	is >> osoba.surname;
	cout << "��'�: ";
	is >> osoba.name;
	cout << "��-�������: ";
	is >> osoba.middleName;
	cout << "���� ����������: ";
	is >> osoba.birthDate;
	cout << "�����: ";
	is >> osoba.gender;
	return is;
}

// �������������� <<
std::ostream& operator<<(std::ostream& os, Osoba& osoba)
{
	os << "\n" << osoba.surname << " " << osoba.name << " " << osoba.middleName << endl;
	os << "���� ����������: " << osoba.birthDate << endl;
	os << "�����: '" << osoba.gender << "'" << endl;
	return os;
}
