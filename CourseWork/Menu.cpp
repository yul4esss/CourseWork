#include "Menu.h"
#include <cctype>

using namespace std;


void Menu::checkInputValidity(int &value)
{
    cout << "Оберіть опцію" << endl;
    cin >> value;
    if (!cin) {
        cin.clear();
        while (cin.get() != '\n')
            continue;
        throw CustomException("Неправильний тип даних. Введено нечислове значення, спробуйте ще раз:");
    }
    else if (value < 0) {
        throw CustomException("Введене значення не можу бути менше за 0, спробуйте ще раз");
    }
}

void Menu::changeOsobaData(Osoba& o)
{
    int choice;
    do {
        cout << "Що ви хочете змінити?" << endl;
        cout << "1. Прізвище" << endl;
        cout << "2. Ім'я" << endl;
        cout << "3. По батькові" << endl;
        cout << "4. Дата народження (у форматі ДД.ММ.РРРР):" << endl;
        cout << "5. Стать" << endl;
        cout << "6. Вивести змінені дані" << endl;
        cout << "7. Повернутися до роботи з класом ОСОБА" << endl;

        string newValue;
        checkInputValidity(choice);

        switch (choice)
        {
        case 1:
            cout << "Введіть нове прізвище: ";
            cin >> newValue;
            o.SetSurname(newValue);
            break;
        case 2:
            cout << "Введіть нове ім'я: ";
            cin >> newValue;
            o.SetName(newValue);
            break;
        case 3:
            cout << "Введіть нове по-батькові: ";
            cin >> newValue;
            o.SetMiddleName(newValue);
            break;
        case 4:
            cout << "Введіть нову дату народження: ";
            cin >> newValue;
            o.SetBirthDate(newValue);
            break;
        case 5:
            cout << "Введіть нову стать: ";
            cin >> newValue;
            o.SetGender(newValue);
            break;
        case 6:
            cout << o;
            break;
        case 7:
            return;
        default:
            throw CustomException("Неправильна опція, спробуйте ще раз");
            break;
        }
    } while (choice != 7);
   
}

void Menu::showOsobaFunctionality(int option)
{
    

    bool isObjectCreated = false;

    Osoba secondPerson;
    Osoba thirdPerson;
    Osoba fourthPerson;
    Osoba sixPerson;
    Osoba seventhPerson;

    do {
        try {
            cout << endl;
            cout << "Робота з класом ОСОБА" << endl;
            cout << "1. Створення об'єкта класу " << endl;
            cout << "2. Робота конструктора за замовчуванням " << endl;
            cout << "3. Робота конструктора ініціалізації " << endl;
            cout << "4. Робота конструктора копіювання " << endl;
            cout << "5. Зміна значень для об'єкта класу " << endl;
            cout << "6. Перевантажена операція = " << endl;
            cout << "7. Перевантаженна потоку введення >> " << endl;
            cout << "8. Перевантаженна потоку виведення << " << endl;
            cout << "9. Перехід до головного меню " << endl;

            checkInputValidity(option);

            switch (option)
            {
            case 1:
                if (!isObjectCreated) {
                    Osoba firstPerson;
                    isObjectCreated = true;
                    cout << "Об'єкт створено" << endl;
                }
                else {
                    cout << "Об'єкт вже створений!" << endl;
                }
                break;
            case 2:
                cout << endl;
                cout << secondPerson.printPersonInfo() << endl;
                break;
            case 3: {
                string surname, name, middleName, birthDate, gender;
                cout << "Прізвище: ";
                cin >> surname;
                cout << "Ім'я: ";
                cin >> name;
                cout << "По батькові: ";
                cin >> middleName;
                cout << "Дата народження (у форматі ДД.ММ.РРРР): ";
                cin >> birthDate;
                cout << "Стать: ";
                cin >> gender;
                thirdPerson = Osoba(surname, name, middleName, birthDate, gender);
                cout << "Результат ініціалізації" << endl;
                cout << thirdPerson;
                cout << endl;
                break;
            }
            case 4:
                fourthPerson = Osoba(thirdPerson);  // Використовуємо конструктор копіювання
                cout << "Копія об'єкту створена" << endl;
                cout << fourthPerson;
                cout << endl;
                break;

            case 5:
                cout << endl;
                changeOsobaData(thirdPerson);
                cout << thirdPerson;
                cout << endl;
                break;

            case 6:
                sixPerson = thirdPerson;
                cout << endl;
                cout << sixPerson;
                break;
            case 7:
                cout << endl;
                cin >> seventhPerson;
                break;
            case 8:
                cout << endl;
                cout << seventhPerson;
                break;
            case 9:
                return;
                //default для основного switch
            default:
                throw CustomException("Неправильна опція, спробуйте ще раз");
                break;
            }
        }
        catch (CustomException& ex) {
            cerr << "Помилка: " << ex.what() << endl;
        }
        

    } while (option != 9);
}


void Menu::changeCoworkerData(Coworker& c)
{
    int choice;
    do {
        cout << "Що ви хочете змінити?" << endl;
        cout << "1. Прізвище" << endl;
        cout << "2. Ім'я" << endl;
        cout << "3. По батькові" << endl;
        cout << "4. Дата народження (у форматі ДД.ММ.РРРР):" << endl;
        cout << "5. Стать" << endl;
        cout << "6. Табельний номер" << endl;
        cout << "7. Оклад" << endl;
        cout << "8. Стаж роботи" << endl;
        cout << "9. Кількість відпрацьованих годин" << endl;
        cout << "10. ЗП/год роботи" << endl;
        cout << "11. Вивести змінені дані" << endl;
        cout << "12. Повернутися до роботи з класом СПІВРОБІТНИК" << endl;

        string newValue;
        checkInputValidity(choice);

        switch (choice)
        {
        case 1:
            cout << "Введіть нове прізвище: ";
            cin >> newValue;
            c.SetSurname(newValue);
            break;
        case 2:
            cout << "Введіть нове ім'я: ";
            cin >> newValue;
            c.SetName(newValue);
            break;
        case 3:
            cout << "Введіть нове по-батькові: ";
            cin >> newValue;
            c.SetMiddleName(newValue);
            break;
        case 4:
            cout << "Введіть нову дату народження: ";
            cin >> newValue;
            c.SetBirthDate(newValue);
            break;
        case 5:
            cout << "Введіть нову стать: ";
            cin >> newValue;
            c.SetGender(newValue);
            break;
        case 6:
            int tableNumber;
            cout << "Введіть новий табельний номер: ";
            cin >> tableNumber;
            c.SetTableNumber(tableNumber);
            break;
        case 7:
            double salary;
            cout << "Введіть новий оклад: ";
            cin >> salary;
            c.SetSalary(salary);
            break;
        case 8:
            double experience;
            cout << "Введіть новий стаж роботи: ";
            cin >> experience;
            c.SetExperience(experience);
            break;
        case 9:
            double hoursWorked;
            cout << "Введіть нову кількість відпрацьованих годин: ";
            cin >> hoursWorked;
            c.SetHoursWorked(hoursWorked);
            break;
            double salaryPerHour;
            cout << "Введіть нову ЗП/год роботи: ";
            cin >> salaryPerHour;
            c.SetSalaryPerHour(salaryPerHour);
            break;
        case 11:
            cout << c;
            break;
        case 12:
            return;
        default:
            throw CustomException("Неправильна опція, спробуйте ще раз");
            break;
        }
    } while (choice != 12);
}

void Menu::showCoworkerFunctionality(int option)
{
    cout << "Робота з класом СПІВРОБІТНИК" << endl;
    cout << "Створіть об'єкт класу " << endl;

    Coworker coworker;
    cin >> coworker;


    Coworker newCoworker;

    do {
        cout << "1. Змінити значення для об'єкту" << endl;
        cout << "2. Вивести інформацію про об'єкт" << endl;
        cout << "3. Перевантаженна потоку введення >>" << endl;
        cout << "4. Перевантаженна потоку виведення << " << endl;
        cout << "5. Повернутися до головного меню" << endl;

        checkInputValidity(option);

        switch (option)
        {

        case 1:
            changeCoworkerData(coworker);
            break;
        case 2:
            cout << coworker.printPersonInfo() << endl;
            break;
        case 3:
            cout << "Демонстрація перевантаження >> " << endl;
            cin >> newCoworker;
            break;
        case 4:
            cout << "Демонстрація перевантаження << " << endl;
            cout << newCoworker;
            break;
        case 5:
            return;
        default:
            throw CustomException("Неправильна опція, спробуйте ще раз");
            break;
        }
    } while (option != 5);

    
}

void Menu::showSalaryFunctionality(int option)
{
    int size;
    cout << "Введіть розмір масиву співробітників: ";
    cin >> size;

    Salary salary(size);
    Coworker* coworker = new Coworker[size];

    do {
        cout << "1. Додати співробітника" << endl;
        cout << "2. Розрахувати зарплату" << endl;
        cout << "3. Вивести інформацію про співробітників" << endl;
        cout << "4. Вийти" << endl;

        checkInputValidity(option);
        switch (option)
        {

        case 1: {
            for (int i = 0; i < size; i++) {
                cout << "Введіть дані про співробітника " << i + 1 << ":" << endl;
                cin >> coworker[i];
                salary.addCoworkerToList(coworker[i]);
                cout << "Співробітник " << i + 1 << " доданий до списку." << endl;
            }
            break;
        }

        case 2: {
            salary.calculateSalary();
            cout << "Зарплати розраховано." << endl;
            cout << "Інформація про співробітників:" << endl;
            cout << salary.printCoworkersInfo() << endl;
            break;
        }

        case 3: {
            cout << "Інформація про співробітників:" << endl;
            CustomIterator begin(coworker, 0, size);
            CustomIterator end(coworker + size, size, size);
            for (CustomIterator it = begin; it != end; it++) {
                cout << (*it).printPersonInfo() << endl;
            }
            // Handle displaying information using the iterator
            break;
        }

        case 4:
            return;

        default:
            throw CustomException("Неправильна опція, спробуйте ще раз");
            break;
        }
    } while (option != 4);

    delete[] coworker; // Remember to deallocate the dynamically allocated array
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

    int choice = 0;

    do {
        cout << "1. Демонстрація основного функціоналу класу ОСОБА" << endl;
        cout << "2. Демонстрація основного функціоналу класу СПІВРОБІТНИК" << endl;
        cout << "3. Демонстрація основного функціоналу класу ЗАРПЛАТА" << endl;
        cout << "4. Демонстрація раннього та пізнього зв'язування" << endl;
        cout << "5. Завершення роботи програми" << endl;
        try {
            checkInputValidity(choice);

            switch (choice)
            {
            case 1:
                showOsobaFunctionality(choice);
                break;

            case 2:
                showCoworkerFunctionality(choice);
                break;

            case 3:
                showSalaryFunctionality(choice);
                break;

            case 4:
            {
                string surname, name, middleName, birthDate, gender;
                int tableNumber;
                double salary, experience, hoursWorked, salaryPerHour;
                
                cout << "Прізвище: ";
                cin >> surname;
                cout << "Ім'я: ";
                cin >> name;
                cout << "По батькові: ";
                cin >> middleName;
                cout << "Дата народження (у форматі ДД.ММ.РРРР): ";
                cin >> birthDate;
                cout << "Стать: ";
                cin >> gender;
                cout << "Табельний номер: " << endl;
                cin >> tableNumber;
                cout << "Оклад: " << endl;
                cin >> salary;
                cout << "Досвід роботи: " << endl;
                cin >> experience;
                cout << "Кількість відпрацьованих годин: " << endl;
                cin >> hoursWorked;
                cout << "ЗП/год роботи: " << endl;
                cin >> salaryPerHour;

                Osoba person(surname, name, middleName, birthDate, gender);
                cout << "Раннє зв'язування (прізвище працівника): " << person.GetPersonData() << endl;

                // Late Binding
                Osoba* worker = new Coworker(surname, name, middleName, birthDate, gender, tableNumber, salary, experience, hoursWorked, salaryPerHour);
                cout << "Пізнє зв'язування (табельний номер працівника): " << worker->GetPersonData() << endl;


                break;
            }

            case 5:
                break;
            default:
                throw CustomException("Неправильне введення даних");
                break;
            }
        }
        catch (CustomException& ex) {
            cerr << "Помилка: " << ex.what() << endl;
        }
    } while (choice != 5);
}