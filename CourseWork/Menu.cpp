#include "Menu.h"

using namespace std;

void NotNumberException() {
	if (!cin) {
		cin.clear();
		while (cin.get() != '\n')
			continue;
		throw CustomException("������� ��� �����. ������� ��������� ��������.");
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
	cout << "\n        ������ ��� ��� ����������   " << endl << endl;
	do {
		try {
			
			
			cout << "������ ������� ����������" << endl;

			int numberOfEmployees;

			cin >> numberOfEmployees;

			NotNumberException();

			cout << "���� �����, ��������� ��� ��� ����������" << endl;

			// ����� ����������
			Coworker* coworkers = new Coworker[numberOfEmployees];
			CustomIterator begin(coworkers, 0, numberOfEmployees);
			CustomIterator end(coworkers + numberOfEmployees, numberOfEmployees, numberOfEmployees);

			for (int i = 0; i < numberOfEmployees; i++) {
				cout << "������ ��� ��� ����������� " << i + 1 << ":" << endl;
				cin >> coworkers[i];
			}

			for (CustomIterator it = begin; it != end; it++) {
				cout << (*it).GetSurname() << endl;
			}

			cout << "2. �������� �� 2" << endl;
			cout << "3. �����" << endl;
			cout << "������� �����: ";
			cin >> choice;

			if (!cin) {
				cin.clear();
				while (cin.get() != '\n')
					continue;
				throw CustomException("������� ��� �����. ������� ��������� ��������.");
			}

			

			switch (choice) {
			case 1:
				// �������� �� 1
				
				break;
			case 2:
				// �������� �� 2
				cout << "���������� �� 2" << endl;
				break;
			case 3:
				// ����� � ��������
				cout << "�������� ������� ������." << endl;
				return;
			default:
				throw CustomException("������ �����. ��������� �� ���.");
			}
		}
		catch (CustomException& ex) {
			cout << "�������: " << ex.getError() << endl;
		}
	} while (true);
}
