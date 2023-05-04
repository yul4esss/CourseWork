#include <Windows.h>
#include <iostream>
#include <string>
#include "Osoba.h"
#include "Coworker.h"
#include "Salary.h"


using namespace std;

int main() {

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


	return 0;
}