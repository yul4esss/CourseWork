#include "Menu.h"

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

void Menu::displayMenu()
{
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

	int choice;
	//int numberOfCoworkers;
	int numberOfPersons;
	Osoba* persons;
	Osoba person;
	Coworker coworker;
	//Salary salary(numberOfCoworkers);

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
				cout << "Створіть об'єкт класу ОСОБА" << endl;
				cin >> person;
				cout << "Оберіть дію над об'єктом класу" << endl;
				cout << "1. Додати новий об'єкт класу" << endl;
				cout << "2. Продемонструвати конструктор ініціалізації" << endl;
				cout << "3. Показати роботу конструктора копіювання" << endl;
				cout << "4. Змінити значення для об'єкта" << endl;

				checkInputValidity(choice);
				switch (choice)
				{
				case 1:
					cout << "Введіть кількість осіб" << endl;
					checkInputValidity(numberOfPersons);

					persons = new Osoba[numberOfPersons];
					break;
				default:
					throw CustomException("Неправильна опція, спробуйте ще раз");
					break;
				}
				break;
			default:
				throw CustomException("Неправильна опція, спробуйте ще раз");
				break;
			}
		}
		catch (CustomException& ex) {
			cerr<< "Помилка: " << ex.getError() << endl;
		}
	} while (true);
}

