#include <Windows.h>
#include <iostream>
#include <string>
#include <cctype>
#include "Osoba.h"
#include "Coworker.h"
#include "Salary.h"
#include "CustomIterator.h"
#include "CustomException.h"
#include "Menu.h"

using namespace std;


int main() {

	// Встановлення мови введення та виведення
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "It's an office application for editing and getting information about employees" << endl;

	Osoba personOne("Сапса", "Юлія", "Петрівна", "11.02.2004", 'Ж');
	cout << personOne.printPersonInfo() << endl;

	/*Osoba personTwo("Гриців", "Ярина", "Ярославівна", "23.10.2003", 'Ж');
	cout << personTwo.printPersonInfo() << endl;*/

	/*Osoba personThree;

	cin >> personThree;
	cout << personThree;*/

	/*Coworker person;
	cin >> person;
	cout << person;*/

	Osoba* o = new Coworker("Сапса", "Юлія", "Петрівна", "11.02.2004", 'Ж', 6, 23, 43, 1, 4.4);


	cout << "Раннє зв'язування(прізвище працівника): " << personOne.GetPersonData() << endl;
	cout << "Пізнє зв'язування(табличний номер працівника): " << o->GetPersonData() << endl;

	int size = 10;
	Salary salary(size);

	Coworker worker("Сапса", "Юлія", "Петрівна", "11.02.2004", 'Ж', 6, 23, 43, 150, 4.46);
	Coworker worker1("Прокопів", "Андрій", "Андрійович", "23.11.2003", 'М', 3, 3.6, 3, 4, 45);

	//cout << worker.printPersonInfo() << endl;
	//cout << worker1.printPersonInfo() << endl;

	salary.addCoworkerToList(worker);
	salary.addCoworkerToList(worker1);
	salary.calculateSalary();
	cout << salary.printCoworkersInfo();

	/*const int ar = 3;
	Coworker coworkers[ar];

	for (int i = 0; i < ar; i++) {
		cout << "Введіть дані про співробітника " << i + 1 << ":" << endl;
		cin >> coworkers[i];
	}

	CustomIterator begin(coworkers, 0, 3);
	CustomIterator end(coworkers + 3, 3, 3);

	for (CustomIterator it = begin; it != end; it++) {
		cout << (*it).GetSurname() << endl;
	}*/

	Menu menu;
	menu.displayMenu();


	return 0;
}