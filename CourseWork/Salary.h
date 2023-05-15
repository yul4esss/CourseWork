#pragma once
#include <string>
#include "Osoba.h"
#include "Coworker.h"
#include "CustomIterator.h"
#include <cctype>


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

    CustomIterator begin() {
        return CustomIterator(coworkersListInfo, 0, amountOfCoworkers);
    }

    // ʳ������ ��������
    CustomIterator end() {
        return CustomIterator(coworkersListInfo, amountOfCoworkers, amountOfCoworkers);
    }

};