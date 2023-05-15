#pragma once
#include <string>
#include "Osoba.h"
#include "Coworker.h"
#include "CustomIterator.h"
#include <cctype>


class Salary {

private:
    Coworker* coworkersListInfo; // Вказівник на динамічний масив
    int amountOfCoworkers;

public:
    Salary(int size) {
        amountOfCoworkers = 0;
        coworkersListInfo = new Coworker[size];
    }

    ~Salary() {
        delete[] coworkersListInfo;
    }

    void addCoworkerToList(Coworker coworker);
    void calculateSalary();
    std::string printCoworkersInfo();

    CustomIterator begin() {
        return CustomIterator(coworkersListInfo, 0, amountOfCoworkers);
    }

    // Кінцевий ітератор
    CustomIterator end() {
        return CustomIterator(coworkersListInfo, amountOfCoworkers, amountOfCoworkers);
    }

};