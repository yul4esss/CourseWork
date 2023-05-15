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
		throw CustomException("Неправильний тип даних. Введено нечислове значення, спробуйте ще раз");
	}

}



void Menu::addPerson(Osoba*& people, int& peopleAmount)
{
	cout << "Введіть кількість осіб: ";
	checkInputValidity(peopleAmount);

	people = new Osoba[peopleAmount];

	for (int i = 0; i < peopleAmount; i++) {
		cout << "Введіть дані про " << i + 1 << " особу: ";
		cin >> people[i];
	}
}

void Menu::updatePersons(Osoba*& people, int peopleAmount)
{
	Osoba* newPeople = new Osoba[peopleAmount + 1];

	for (int i = 0; i < peopleAmount; i++) {
		newPeople[i] = people[i];
	}

	cout << "Введіть дані про " << peopleAmount + 1 << " особу: ";
	cin >> newPeople[peopleAmount];

	delete[] people;
	people = newPeople;
	peopleAmount++;
}

void Menu::changePersonInfo(Osoba* people, int peopleAmount)
{
	string surname;
	cout << "Введіть прізвище особи, для якої хочете змінити дані: ";
	cin >> surname;

	// Знаходимо особу за прізвищем
	int personIndex = -1;
	for (int i = 0; i < peopleAmount; i++) {
		if (people[i].GetSurname() == surname) {
			personIndex = i;
			break;
		}
	}

	if (personIndex == -1) {
		cout << "Особа з прізвищем '" << surname << "' не знайдена." << endl;
		return;
	}

	cout << "Оберіть параметр, який хочете змінити:" << endl;
	cout << "1. Прізвище" << endl;
	cout << "2. Ім'я" << endl;
	cout << "3. По батькові" << endl;
	cout << "4. Дата народження" << endl;
	cout << "5. Стать" << endl;

	int choice;
	checkInputValidity(choice);

	switch (choice)
	{
	case 1:
	{
		string newSurname;
		cout << "Введіть нове прізвище: ";
		cin >> newSurname;
		people[personIndex].SetSurname(newSurname);
		break;
	}
	case 2:
	{
		string newName;
		cout << "Введіть нове ім'я: ";
		cin >> newName;
		people[personIndex].SetName(newName);
		break;
	}
	case 3:
	{
		string newMiddleName;
		cout << "Введіть нове по батькові: ";
		cin >> newMiddleName;
		people[personIndex].SetMiddleName(newMiddleName);
		break;
	}
	case 4:
	{
		string newBirthDate;
		cout << "Введіть нову дату народження: ";
		cin >> newBirthDate;
		people[personIndex].SetBirthDate(newBirthDate);
		break;
	}
	case 5:
	{
		string newGender;
		cout << "Введіть нову стать: ";
		cin >> newGender;
		people[personIndex].SetGender(newGender);
		break;
	}
	default:
		throw CustomException("Неправильна опція, спробуйте ще раз");
	}
}


void Menu::displayMenu()
{
	int choice;
	int numberOfPersons = 0;
	Osoba* persons = nullptr;

	cout << "------------------------------------------" << endl;
	cout << "|             Курсова робота             |" << endl;
	cout << "|         Студентки групи КН-22/2        |" << endl;
	cout << "|              Сапси Юлії                |" << endl;
	cout << "|              Варіант 21                |" << endl;
	cout << "------------------------------------------" << endl;
	cout << "|                                        |" << endl;
	cout << "|                 Меню                   |" << endl;
	cout << "|                                        |" << endl;
	cout << "------------------------------------------" << endl;

	do {
		try {
			cout << "Введіть опцію" << endl;
			cout << "1. Робота з класом ОСОБА" << endl;
			cout << "2. Робота з класом СПІВРОБІТНИК" << endl;
			cout << "3. Робота з класом ЗАРПЛАТА" << endl;

			checkInputValidity(choice);

			switch (choice)
			{
			case 1:
				cout << "Робота з класом ОСОБА" << endl;

				do {
					cout << "Оберіть дію над об'єктом класу" << endl;
					cout << "1. Додати новий об'єкт класу" << endl;
					cout << "2. Змінити значення для об'єкта" << endl;
					cout << "3. Вивести інформацію про осіб" << endl;
					cout << "4. Повернутися до головного меню" << endl;

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
							cout << "Спочатку створіть початковий список осіб" << endl;
							break;
						}
						updatePersons(persons, numberOfPersons);
						break;
					case 3:
						if (persons == nullptr) {
							cout << "Спочатку створіть об'єкт класу ОСОБА" << endl;
							break;
						}
						for (int i = 0; i < numberOfPersons; i++) {
							cout << persons[i].printPersonInfo() << endl;
						}
						break;
					case 4:
						break;
					default:
						throw CustomException("Неправильна опція, спробуйте ще раз");
						break;
					}
				} while (choice != 4);
			}
		}
		catch (CustomException& ex) {
			cerr << "Помилка: " << ex.what() << endl;
		}
		
	} while (choice != 4);
}



