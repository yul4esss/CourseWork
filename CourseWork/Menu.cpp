#include "Menu.h"

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

void Menu::displayMenu()
{
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

	int choice;
	//int numberOfCoworkers;
	int numberOfPersons;
	Osoba* persons;
	Osoba person;
	Coworker coworker;
	//Salary salary(numberOfCoworkers);

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
				cout << "������� ��'��� ����� �����" << endl;
				cin >> person;
				cout << "������ �� ��� ��'����� �����" << endl;
				cout << "1. ������ ����� ��'��� �����" << endl;
				cout << "2. ���������������� ����������� �����������" << endl;
				cout << "3. �������� ������ ������������ ���������" << endl;
				cout << "4. ������ �������� ��� ��'����" << endl;

				checkInputValidity(choice);
				switch (choice)
				{
				case 1:
					cout << "������ ������� ���" << endl;
					checkInputValidity(numberOfPersons);

					persons = new Osoba[numberOfPersons];
					break;
				default:
					throw CustomException("����������� �����, ��������� �� ���");
					break;
				}
				break;
			default:
				throw CustomException("����������� �����, ��������� �� ���");
				break;
			}
		}
		catch (CustomException& ex) {
			cerr<< "�������: " << ex.getError() << endl;
		}
	} while (true);
}

