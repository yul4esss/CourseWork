#pragma once
#include "CustomException.h"
#include "CustomIterator.h"
#include "Coworker.h"
#include "Osoba.h"
#include "Salary.h"
#include <cctype>



class Menu
{
	private: int choice;
	public:

		void displayMenu();

		void checkInputValidity(int &value);

		//void changePersonInfo(int& value, Osoba& o);


		void addPerson(Osoba*& people, int& peopleAmount);
		void updatePersons(Osoba*& people, int peopleAmount);

		void changePersonInfo(Osoba* people, int peopleAmount);

		//void showConstructorWork(Osoba& o, string srnm, string nm, string mdlnm, string bday, char gdr);
};

