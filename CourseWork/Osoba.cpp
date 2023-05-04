#include "Osoba.h"
#include <iostream>
#include <string>


using namespace std;
// Тут описуємо що виконують вже самі функції

// Сеттери для класу Osoba
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

// Геттери для класу Osoba
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

// Вивід інформації про особу
std::string Osoba::printPersonInfo()
{
	string personInfo = surname + " " + name + " " + middleName + "\nДата народження: " + birthDate
		+ "\nСтать: '" + std::string(1, gender) + "'";
	return personInfo;
}

// Перевантаження ()
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

// Перевантаження =
Osoba& Osoba::operator=(const Osoba& other)
{

	// Перевірка чи є вже такі значення у об'єкта
	if (this != &other) {
		surname = other.surname;
		name = other.name;
		middleName = other.middleName;
		birthDate = other.birthDate;
		gender = other.gender;
	}

	return *this;
}

// Перевантаження >>
std::istream& operator>>(std::istream& is, Osoba& osoba)
{
	cout << "Прізвище: ";
	is >> osoba.surname;
	cout << "Ім'я: ";
	is >> osoba.name;
	cout << "По-батькові: ";
	is >> osoba.middleName;
	cout << "Дата народження: ";
	is >> osoba.birthDate;
	cout << "Стать: ";
	is >> osoba.gender;
	return is;
}

// Перевантаження <<
std::ostream& operator<<(std::ostream& os, Osoba& osoba)
{
	os << "\n" << osoba.surname << " " << osoba.name << " " << osoba.middleName << endl;
	os << "Дата народження: " << osoba.birthDate << endl;
	os << "Стать: '" << osoba.gender << "'" << endl;
	return os;
}
