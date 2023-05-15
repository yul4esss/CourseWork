#include "Osoba.h"
#include "CustomException.h"
#include <iostream>
#include <string>
#include <cctype>
#include <regex>
#include <chrono>


using namespace std;
// ��� ������� �� ��������� ��� ��� �������

Osoba::Osoba()
{
	surname = "";
	name = "";
	middleName = "";
	birthDate = "";
	gender = "";
}

Osoba::Osoba(std::string surname, std::string name, std::string middleName, std::string birthDate, std::string gender)
{

	this->surname = surname;
	this->name = name;
	this->middleName = middleName;
	this->birthDate = birthDate;
	this->gender = gender;

	if (containsDigit(surname))
		throw CustomException("������� �� ������� ������ �����");
	if (containsDigit(name))
		throw CustomException("��'� �� ������� ������ �����");
	if (containsDigit(middleName))
		throw CustomException("�� ������� �� ������� ������ �����");
	/*if (gender != "�" && gender != "�")
		throw CustomException("����� �� ���� ������� �� '�' ��� '�'");*/
	checkDateFormat(birthDate);

}

Osoba::Osoba(const Osoba& other)
{
	surname = other.surname;
	name = other.name;
	middleName = other.middleName;
	birthDate = other.birthDate;
	gender = other.gender;
}

Osoba::Osoba(int size)
{
	amountOfPersons = 0;
	osobaList = new Osoba[size]();
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


// ������� ��� ����� Osoba
void Osoba::SetSurname(string surname)
{
	this->surname = surname;
	if (containsDigit(surname))
		throw CustomException("������� �� ������� ������ �����");

}

void Osoba::SetName(string name)
{
	this->name = name;
	if (containsDigit(name))
		throw CustomException("��'� �� ������� ������ �����");
}

void Osoba::SetMiddleName(string middleName)
{
	this->middleName = middleName;
	if (containsDigit(middleName))
		throw CustomException("�� ������� �� ������� ������ �����");
}

void Osoba::SetBirthDate(string birthDate)
{
	checkDateFormat(birthDate);
	this->birthDate = birthDate;

}

void Osoba::SetGender(std::string gender)
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

std::string Osoba::GetGender()
{
	return gender;
}

// ���� ���������� ��� �����
std::string Osoba::printPersonInfo()
{
	string personInfo = surname + " " + name + " " + middleName + "\n���� ����������: " + birthDate
		+ "\n�����: '" + gender + "'";
	return personInfo;
}



// �������������� ()
void Osoba::operator()(std::string surname, std::string name, std::string middleName, std::string birthDate, std::string gender)
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

void Osoba::checkDateFormat(const std::string& birthDate)
{
	std::regex dateRegex(R"(^\d{2}\.\d{2}\.\d{4}$)");
	if (!std::regex_match(birthDate, dateRegex))
		throw CustomException("���� ���������� �� ���� � ������ ��.��.����");
	// ��������� ���� �� ������� (����, �����, ��)
	std::string dayStr = birthDate.substr(0, 2);
	std::string monthStr = birthDate.substr(3, 2);
	std::string yearStr = birthDate.substr(6, 4);

	// ����������� ��������� ���� � �������� ������
	int day = std::stoi(dayStr);
	int month = std::stoi(monthStr);
	int year = std::stoi(yearStr);

	// ��������� ������� ���� �� ����
	std::time_t currentTimeT = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::tm localTime;
	localtime_s(&localTime, &currentTimeT);
	int currentYear = localTime.tm_year + 1900;

	// �������� ���������� ������� ���, ����� � ����
	if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0 || year > currentYear) {
		throw CustomException("���������� ���� ����������");
	}
}

// �������������� >>
std::istream& operator>>(std::istream& is, Osoba& osoba)
{
	cout << "�������: ";
	is >> osoba.surname;
	if (osoba.containsDigit(osoba.surname))
		throw CustomException("������� �� ������� ������ �����");
	cout << "��'�: ";
	is >> osoba.name;
	if (osoba.containsDigit(osoba.name))
		throw CustomException("��'� �� ������� ������ �����");
	cout << "��-�������: ";
	is >> osoba.middleName;
	if (osoba.containsDigit(osoba.middleName))
		throw CustomException("�� ������� �� ������� ������ �����");
	cout << "���� ����������: ";
	is >> osoba.birthDate;

	osoba.checkDateFormat(osoba.birthDate);

	cout << "�����: ";
	is >> osoba.gender;
	if (osoba.gender != "�" && osoba.gender != "�")
		throw CustomException("����� �� ���� ������� �� '�' ��� '�'");

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
