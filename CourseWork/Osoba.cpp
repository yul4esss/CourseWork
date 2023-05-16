#include "Osoba.h"
#include "CustomException.h"
#include <iostream>
#include <string>
#include <cctype>
#include <regex>
#include <chrono>


using namespace std;
// Тут описуємо що виконують вже самі функції

Osoba::Osoba()
{
	surname = "none";
	name = "none";
	middleName = "none";
	birthDate = "none";
	gender = "none";
}

Osoba::Osoba(std::string surname, std::string name, std::string middleName, std::string birthDate, std::string gender)
{
	if (containsDigit(surname))
		throw CustomException("Прізвище не повинно містити цифри");
	this->surname = surname;
	if (containsDigit(name))
		throw CustomException("Ім'я не повинно містити цифри");
	this->name = name;
	if (containsDigit(middleName))
		throw CustomException("По батькові не повинно містити цифри");
	this->middleName = middleName;
	checkDateFormat(birthDate);
	this->birthDate = birthDate;
	if (gender != "Ч" && gender != "Ж")
	throw CustomException("Стать має бути вказана як 'Ч' або 'Ж'");
	this->gender = gender;
}

Osoba::Osoba(const Osoba& other)
{
	surname = other.surname;
	name = other.name;
	middleName = other.middleName;
	birthDate = other.birthDate;
	gender = other.gender;
}


bool Osoba::containsDigit(const std::string& value)
{
	for (char c : value) {
		if (std::isdigit(static_cast<unsigned char>(c))) {
			return true;
		}
	}
	return false;
}


// Сеттери для класу Osoba
void Osoba::SetSurname(string surname)
{
	if (containsDigit(surname))
		throw CustomException("Прізвище не повинно містити цифри");
	this->surname = surname;

}

void Osoba::SetName(string name)
{
	if (containsDigit(name))
		throw CustomException("Ім'я не повинно містити цифри");
	this->name = name;
}

void Osoba::SetMiddleName(string middleName)
{
	if (containsDigit(middleName))
		throw CustomException("По батькові не повинно містити цифри");
	this->middleName = middleName;
}

void Osoba::SetBirthDate(string birthDate)
{
	checkDateFormat(birthDate);
	this->birthDate = birthDate;
}

void Osoba::SetGender(std::string gender)
{
	if (gender != "Ч" && gender != "Ж")
		throw CustomException("Стать має бути вказана як 'Ч' або 'Ж'");
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

std::string Osoba::GetGender()
{
	return gender;
}

// Вивід інформації про особу
std::string Osoba::printPersonInfo()
{
	string personInfo = surname + " " + name + " " + middleName + "\nДата народження: " + birthDate
		+ "\nСтать: '" + gender + "'";
	return personInfo;
}



// Перевантаження ()
void Osoba::operator()(std::string surname, std::string name, std::string middleName, std::string birthDate, std::string gender)
{
	if (containsDigit(surname))
		throw CustomException("Прізвище не повинно містити цифри");
	this->surname = surname;
	if (containsDigit(name))
		throw CustomException("Ім'я не повинно містити цифри");
	this->name = name;
	if (containsDigit(middleName))
		throw CustomException("По батькові не повинно містити цифри");
	this->middleName = middleName;
	checkDateFormat(birthDate);
	this->birthDate = birthDate;
	if (gender != "Ч" && gender != "Ж")
		throw CustomException("Стать має бути вказана як 'Ч' або 'Ж'");
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

void Osoba::checkDateFormat(const std::string& birthDate)
{
	std::regex dateRegex(R"(^\d{2}\.\d{2}\.\d{4}$)");
	if (!std::regex_match(birthDate, dateRegex))
		throw CustomException("Дата народження має бути у форматі дд.мм.рррр");
	// Розділення дати на складові (день, місяць, рік)
	std::string dayStr = birthDate.substr(0, 2);
	std::string monthStr = birthDate.substr(3, 2);
	std::string yearStr = birthDate.substr(6, 4);

	// Переведення складових дати у числовий формат
	int day = std::stoi(dayStr);
	int month = std::stoi(monthStr);
	int year = std::stoi(yearStr);

	// Отримання поточної дати та часу
	std::time_t currentTimeT = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::tm localTime;
	localtime_s(&localTime, &currentTimeT);
	int currentYear = localTime.tm_year + 1900;

	// Перевірка коректності значень дня, місяця і року
	if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0 || year > currentYear) {
		throw CustomException("Некоректна дата народження");
	}
}

// Перевантаження >>
std::istream& operator>>(std::istream& is, Osoba& osoba)
{
	cout << "Прізвище: ";
	is >> osoba.surname;
	if (osoba.containsDigit(osoba.surname))
		throw CustomException("Прізвище не повинно містити цифри");
	cout << "Ім'я: ";
	is >> osoba.name;
	if (osoba.containsDigit(osoba.name))
		throw CustomException("Ім'я не повинно містити цифри");
	cout << "По-батькові: ";
	is >> osoba.middleName;
	if (osoba.containsDigit(osoba.middleName))
		throw CustomException("По батькові не повинно містити цифри");
	cout << "Дата народження: ";
	is >> osoba.birthDate;

	osoba.checkDateFormat(osoba.birthDate);

	cout << "Стать: ";
	is >> osoba.gender;
	if (osoba.gender != "Ч" && osoba.gender != "Ж")
		throw CustomException("Стать має бути вказана як 'Ч' або 'Ж'");

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
