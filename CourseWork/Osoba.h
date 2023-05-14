#pragma once
#include <iostream>
#include <string>

using namespace std;

class Osoba
{
protected:
	Osoba* osobaList; // �������� �� ��������� �����
	int amountOfPersons;
	std::string surname;
	std::string name;
	std::string middleName;
	std::string birthDate;
	char gender;

public:
	// ����������� �� �������������
	Osoba() {
		surname = "";
		name = "";
		middleName = "";
		birthDate = "";
		gender = ' ';
	}

	// ����������� �����������
	Osoba(std::string surname, std::string name, std::string middleName, std::string birthDate, char gender) {
		this->surname = surname;
		this->name = name;
		this->middleName = middleName;
		this->birthDate = birthDate;
		this->gender = gender;
	}

	// ����������� ���������
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

	// ����������
	~Osoba() {}

	// ������� ��� ���� ����� Osoba
	void SetSurname(std::string surname);
	void SetName(std::string name);
	void SetMiddleName(std::string middleName);
	void SetBirthDate(std::string birthDate);
	void SetGender(char gender);

	// ������ ��� ���� ����� Osoba
	std::string GetSurname();
	std::string GetName();
	std::string GetMiddleName();
	std::string GetBirthDate();
	char GetGender();


	// ���� ���������� ��� �����
	virtual std::string printPersonInfo();

	Osoba& operator = (const Osoba& other);

	void operator () (std::string surname, std::string name, std::string middleName, std::string birthDate, char gender);

	friend std::istream& operator>>(std::istream& is, Osoba& osoba);
	friend std::ostream& operator<<(std::ostream& os, Osoba& osoba);

	// ³�������� ������� ������� ������� �����
	virtual std::string GetPersonData();
};

