#pragma once
#include <string>
#include "Osoba.h"
#include "Coworker.h"


class Salary {

private:
    Coworker* coworkersListInfo; // �������� �� ��������� �����
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

};