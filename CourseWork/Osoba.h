#pragma once
#include <iostream>
#include <string>


using namespace std;

class Osoba
{
protected:
	Osoba* osobaList; // Вказівник на динамічний масив
	int amountOfPersons;
	std::string surname;
	std::string name;
	std::string middleName;
	std::string birthDate;
	std::string gender;

public:
	// Конструктор за замовчуванням
	Osoba();

	// Конструктор ініціалізації
	Osoba(std::string surname, std::string name, std::string middleName, std::string birthDate, std::string gender);

	// Конструктор копіювання
	Osoba(const Osoba& other);

	Osoba(int size);

	// Деструктор
	~Osoba() {}

	// Сеттери для полів класу Osoba
	void SetSurname(std::string surname);
	void SetName(std::string name);
	void SetMiddleName(std::string middleName);
	void SetBirthDate(std::string birthDate);
	void SetGender(std::string gender);

	// Гетери для полів класу Osoba
	std::string GetSurname();
	std::string GetName();
	std::string GetMiddleName();
	std::string GetBirthDate();
	std::string GetGender();


	// Вивід інформації про особу
	virtual std::string printPersonInfo();

	bool containsDigit(const std::string& value);

	void checkDateFormat(const std::string& birthDate);

	Osoba& operator = (const Osoba& other);

	void operator () (std::string surname, std::string name, std::string middleName, std::string birthDate, std::string gender);

	friend std::istream& operator>>(std::istream& is, Osoba& osoba);
	friend std::ostream& operator<<(std::ostream& os, Osoba& osoba);

	// Віртуальна функція читання прізвища особи
	virtual std::string GetPersonData();
};

