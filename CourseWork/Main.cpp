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
#include <cctype>
#include <regex>

using namespace std;


int main() {

	// Встановлення мови введення та виведення
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	Menu menu;
	menu.displayMenu();


	return 0;
}