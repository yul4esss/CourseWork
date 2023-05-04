#include <Windows.h>
#include <iostream>
#include <string>
#include "Osoba.h"
#include "Coworker.h"
#include "Salary.h"
#include "CustomIterator.h"

using namespace std;

int main() {

	system("chcp 1251");
	// ������������ ���� �������� �� ���������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Osoba personOne("�����", "���", "�������", "11.02.2004", '�');
	cout << personOne.printPersonInfo() << endl;

	/*Osoba personTwo("������", "�����", "����������", "23.10.2003", '�');
	cout << personTwo.printPersonInfo() << endl;*/

	/*Osoba personThree;

	cin >> personThree;
	cout << personThree;*/

	/*Coworker person;
	cin >> person;
	cout << person;*/

	Osoba* o = new Coworker("�����", "���", "�������", "11.02.2004", '�', 6, 23, 43, 1, 4.4);


	cout << "���� ��'��������(������� ����������): " << personOne.GetPersonData() << endl;
	cout << "ϳ�� ��'��������(��������� ����� ����������): " << o->GetPersonData() << endl;

	int size = 10;
	Salary salary(size);

	Coworker worker("�����", "���", "�������", "11.02.2004", '�', 6, 23, 43, 150, 4.46);
	Coworker worker1("�������", "�����", "���������", "23.11.2003", '�', 3, 3.6, 3, 4, 45);

	//cout << worker.printPersonInfo() << endl;
	//cout << worker1.printPersonInfo() << endl;

	salary.addCoworkerToList(worker);
	salary.addCoworkerToList(worker1);
	salary.calculateSalary();
	cout << salary.printCoworkersInfo();

	Coworker coworkers[3] = {
		Coworker("Ivanov", "Ivan", "Ivanovich", "01.01.1990", 'M', 1, 2000.0, 2, 40.0, 50.0),
		Coworker("Petrov", "Petr", "Petrovich", "02.02.1991", 'M', 2, 2500.0, 3, 45.0, 55.0),
		Coworker("Sidorov", "Sidor", "Sidorovich", "03.03.1992", 'M', 3, 3000.0, 4, 50.0, 60.0)
	};

	CustomIterator begin(coworkers, 0, 3);
	CustomIterator end(coworkers + 3, 3, 3);

	for (CustomIterator it = begin; it != end; it++) {
		cout << (*it).GetSurname() << endl;
	}

	return 0;
}