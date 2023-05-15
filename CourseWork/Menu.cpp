#include "Menu.h"
#include <cctype>

using namespace std;


void Menu::checkInputValidity(int &value)
{
	cin >> value;
	if (!cin) {
		cin.clear();
		while (cin.get() != '\n')
			continue;
		throw CustomException("������������ ��� �����. ������� ��������� ��������, ��������� �� ���");
	}

}



void Menu::addPerson(Osoba*& people, int& peopleAmount)
{
	cout << "������ ������� ���: ";
	checkInputValidity(peopleAmount);

	people = new Osoba[peopleAmount];

	for (int i = 0; i < peopleAmount; i++) {
		cout << "������ ��� ��� " << i + 1 << " �����: ";
		cin >> people[i];
	}
}

void Menu::updatePersons(Osoba*& people, int peopleAmount)
{
	Osoba* newPeople = new Osoba[peopleAmount + 1];

	for (int i = 0; i < peopleAmount; i++) {
		newPeople[i] = people[i];
	}

	cout << "������ ��� ��� " << peopleAmount + 1 << " �����: ";
	cin >> newPeople[peopleAmount];

	delete[] people;
	people = newPeople;
	peopleAmount++;
}

void Menu::changePersonInfo(Osoba* people, int peopleAmount)
{
	string surname;
	cout << "������ ������� �����, ��� ��� ������ ������ ���: ";
	cin >> surname;

	// ��������� ����� �� ��������
	int personIndex = -1;
	for (int i = 0; i < peopleAmount; i++) {
		if (people[i].GetSurname() == surname) {
			personIndex = i;
			break;
		}
	}

	if (personIndex == -1) {
		cout << "����� � �������� '" << surname << "' �� ��������." << endl;
		return;
	}

	cout << "������ ��������, ���� ������ ������:" << endl;
	cout << "1. �������" << endl;
	cout << "2. ��'�" << endl;
	cout << "3. �� �������" << endl;
	cout << "4. ���� ����������" << endl;
	cout << "5. �����" << endl;

	int choice;
	checkInputValidity(choice);

	switch (choice)
	{
	case 1:
	{
		string newSurname;
		cout << "������ ���� �������: ";
		cin >> newSurname;
		people[personIndex].SetSurname(newSurname);
		break;
	}
	case 2:
	{
		string newName;
		cout << "������ ���� ��'�: ";
		cin >> newName;
		people[personIndex].SetName(newName);
		break;
	}
	case 3:
	{
		string newMiddleName;
		cout << "������ ���� �� �������: ";
		cin >> newMiddleName;
		people[personIndex].SetMiddleName(newMiddleName);
		break;
	}
	case 4:
	{
		string newBirthDate;
		cout << "������ ���� ���� ����������: ";
		cin >> newBirthDate;
		people[personIndex].SetBirthDate(newBirthDate);
		break;
	}
	case 5:
	{
		string newGender;
		cout << "������ ���� �����: ";
		cin >> newGender;
		people[personIndex].SetGender(newGender);
		break;
	}
	default:
		throw CustomException("����������� �����, ��������� �� ���");
	}
}


void Menu::displayMenu()
{
	int choice;
	int numberOfPersons = 0;
	Osoba* persons = nullptr;

	cout << "------------------------------------------" << endl;
	cout << "|             ������� ������             |" << endl;
	cout << "|         ��������� ����� ��-22/2        |" << endl;
	cout << "|              ����� �볿                |" << endl;
	cout << "|              ������ 21                |" << endl;
	cout << "------------------------------------------" << endl;
	cout << "|                                        |" << endl;
	cout << "|                 ����                   |" << endl;
	cout << "|                                        |" << endl;
	cout << "------------------------------------------" << endl;

	do {
		try {
			cout << "������ �����" << endl;
			cout << "1. ������ � ������ �����" << endl;
			cout << "2. ������ � ������ �ϲ���������" << endl;
			cout << "3. ������ � ������ ��������" << endl;

			checkInputValidity(choice);

			switch (choice)
			{
			case 1:
				cout << "������ � ������ �����" << endl;

				do {
					cout << "������ �� ��� ��'����� �����" << endl;
					cout << "1. ������ ����� ��'��� �����" << endl;
					cout << "2. ������ �������� ��� ��'����" << endl;
					cout << "3. ������� ���������� ��� ���" << endl;
					cout << "4. ����������� �� ��������� ����" << endl;

					checkInputValidity(choice);

					switch (choice)
					{
					case 1:
						if (persons != nullptr) {
							delete[] persons;
							persons = nullptr;
							numberOfPersons = 0;
						}
						addPerson(persons, numberOfPersons);
						break;
					case 2:
						if (persons == nullptr) {
							cout << "�������� ������� ���������� ������ ���" << endl;
							break;
						}
						updatePersons(persons, numberOfPersons);
						break;
					case 3:
						if (persons == nullptr) {
							cout << "�������� ������� ��'��� ����� �����" << endl;
							break;
						}
						for (int i = 0; i < numberOfPersons; i++) {
							cout << persons[i].printPersonInfo() << endl;
						}
						break;
					case 4:
						break;
					default:
						throw CustomException("����������� �����, ��������� �� ���");
						break;
					}
				} while (choice != 4);
			}
		}
		catch (CustomException& ex) {
			cerr << "�������: " << ex.what() << endl;
		}
		
	} while (choice != 4);
}



