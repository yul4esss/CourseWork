#include "Menu.h"

using namespace std;

void NotNumberException() {
	if (!cin) {
		cin.clear();
		while (cin.get() != '\n')
			continue;
		throw CustomException("Невірний тип даних. Введено нечислове значення.");
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
	cout << "\n        Введіть дані про працівників   " << endl << endl;
	do {
		try {
			
			
			cout << "Введіть кількість працівників" << endl;

			int numberOfEmployees;

			cin >> numberOfEmployees;

			NotNumberException();

			cout << "Будь ласка, заповність дані про працівників" << endl;

			// Масив працівників
			Coworker* coworkers = new Coworker[numberOfEmployees];
			CustomIterator begin(coworkers, 0, numberOfEmployees);
			CustomIterator end(coworkers + numberOfEmployees, numberOfEmployees, numberOfEmployees);

			for (int i = 0; i < numberOfEmployees; i++) {
				cout << "Введіть дані про співробітника " << i + 1 << ":" << endl;
				cin >> coworkers[i];
			}

			for (CustomIterator it = begin; it != end; it++) {
				cout << (*it).GetSurname() << endl;
			}

			cout << "2. Виконати дію 2" << endl;
			cout << "3. Вийти" << endl;
			cout << "Виберіть опцію: ";
			cin >> choice;

			if (!cin) {
				cin.clear();
				while (cin.get() != '\n')
					continue;
				throw CustomException("Невірний тип даних. Введено нечислове значення.");
			}

			

			switch (choice) {
			case 1:
				// Виконати дію 1
				
				break;
			case 2:
				// Виконати дію 2
				cout << "Виконується дія 2" << endl;
				break;
			case 3:
				// Вийти з програми
				cout << "Програма завершує роботу." << endl;
				return;
			default:
				throw CustomException("Невірна опція. Спробуйте ще раз.");
			}
		}
		catch (CustomException& ex) {
			cout << "Помилка: " << ex.getError() << endl;
		}
	} while (true);
}
