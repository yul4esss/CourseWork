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
	char gender;

public:
	// Конструктор за замовчуванням
	Osoba() {
		surname = "";
		name = "";
		middleName = "";
		birthDate = "";
		gender = ' ';
	}

	// Конструктор ініціалізації
	Osoba(std::string surname, std::string name, std::string middleName, std::string birthDate, char gender) {
		this->surname = surname;
		this->name = name;
		this->middleName = middleName;
		this->birthDate = birthDate;
		this->gender = gender;
	}

	// Конструктор копіювання
	Osoba(const Osoba& other) {
		surname = other.surname;
		name = other.name;
		middleName = other.middleName;
		birthDate = other.birthDate;
		gender = other.gender;
	}

	Osoba(int size) {
		amountOfPersons = 0;
		osobaList = new Osoba[size];
	}

	// Деструктор
	~Osoba() {}

	// Сеттери для полів класу Osoba
	void SetSurname(std::string surname);
	void SetName(std::string name);
	void SetMiddleName(std::string middleName);
	void SetBirthDate(std::string birthDate);
	void SetGender(char gender);

	// Гетери для полів класу Osoba
	std::string GetSurname();
	std::string GetName();
	std::string GetMiddleName();
	std::string GetBirthDate();
	char GetGender();


	// Вивід інформації про особу
	virtual std::string printPersonInfo();

	Osoba& operator = (const Osoba& other);

	void operator () (std::string surname, std::string name, std::string middleName, std::string birthDate, char gender);

	friend std::istream& operator>>(std::istream& is, Osoba& osoba);
	friend std::ostream& operator<<(std::ostream& os, Osoba& osoba);

	// Віртуальна функція читання прізвища особи
	virtual std::string GetPersonData();
};

