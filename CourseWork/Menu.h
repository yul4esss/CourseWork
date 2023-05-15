#pragma once
#include "CustomException.h"
#include "CustomIterator.h"
#include "Coworker.h"
#include "Osoba.h"
#include "Salary.h"
#include <cctype>

using namespace std;

class Menu
{
	private: int choice;
	public:

		void displayMenu();

		void checkInputValidity(int &value);

		void changeOsobaData(Osoba& o);
		void showOsobaFunctionality(int option);


		void changeCoworkerData(Coworker& c);
		void showCoworkerFunctionality(int option);

		void showSalaryFunctionality(int option);
};

