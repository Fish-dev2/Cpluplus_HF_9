//JI9J9A Füzi Bálint FELADAT9V1
#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

#include "CWageEmployee.h"
#include "CSalesPerson.h"
#include "CManager.h"
#include "CEmployee.h"

using namespace std;


const string menuOptions[] = { "Bevitel", "Lista", "Fizetes nev alapjan", "Fizetes csokkeno", "Fizetes novekvo", "Kilepes"};
const int optionSize = 6;


using EmployeeList = vector<CEmployee*>;

void createEmployee(EmployeeList& empList) {
    int choice;
    cout << "Valaszd ki milyen employeet akarsz:" << endl;
    cout << "1. Wage Employee" << endl;
    cout << "2. Sales Employee" << endl;
    cout << "3. Manager" << endl;
    cout << "Ird be a menupont szamat: ";
    cin >> choice;
    if (cin.fail() || choice <1 || choice > 3)
    {
        cout << "Hibas valasztas. Letrehozas megszakitva." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    CEmployee* emp = nullptr;
    switch (choice) {
        case 1: {
            emp = new CWageEmployee();
            break;
        }
        case 2: {
            emp = new CSalesPerson();
            break;
        }
        case 3: {
            emp = new CManager();
            break;
        }
    }
    emp->Input();
    if (cin.fail())
    {
        cout << "Hibas adatbevitel." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    empList.push_back(emp);
}
void listEmployees(const EmployeeList& empList) {
    if (empList.empty()) {
        cout << "Nem hoztal letre meg egy employeet se." << endl;
        return;
    }

    cout << "Employee lista:" << endl;
    cout << endl;
    for (size_t i = 0; i < empList.size(); ++i) {
        cout << "\t";
        cout << "Employee " << i + 1 << ":" << endl;
        empList[i]->Display();
        cout << "Fizetes:" << empList[i]->ComputePay() << endl;
        cout << endl;
    }
}
void payByName(const EmployeeList& empList) {
    if (empList.empty()) {
        cout << "Nem hoztal letre meg egy employeet se." << endl;
        return;
    }

    string searchName;
    cout << "Add meg a keresett employee nevet: ";
    cin >> searchName;

    size_t i = 0;
    while (i < empList.size() && empList[i]->getName() != searchName)
    {
        ++i;
    }
    if (i < empList.size())
    {
        cout << searchName << " fizetese: " << empList[i]->ComputePay() << endl;
    }
    else
    {
        cout << searchName << " nevu employee nincs a listaban." << endl;
    }
}
void listPays(const EmployeeList& empList, bool descending) {
    if (empList.empty()) {
        cout << "Nem hoztal letre meg egy employeet se." << endl;
        return;
    }


    vector<CEmployee*> sorted = empList;
    float paySum = 0.0f;

    for (size_t i = 0; i < sorted.size() - 1; ++i) {
        size_t smallestIndex = i;
        for (size_t j = i + 1; j < sorted.size(); ++j) {
            if (sorted[j]->ComputePay() < sorted[smallestIndex]->ComputePay()) {
                smallestIndex = j;
            }
        }
        if (smallestIndex != i) {
            std::swap(sorted[i], sorted[smallestIndex]);
        }
        paySum += sorted[i]->ComputePay(); 
    }

    float avg = paySum / sorted.size();

    if (descending)
    {
        reverse(sorted.begin(), sorted.end());
    }
    listEmployees(sorted);
    cout << "Atlag fizetes: " << avg << endl;


}


void displayMenu() {
    cout << "=== Menu ===" << endl;
    for (int i = 0; i < optionSize; ++i) {
        cout << i + 1 << ". " << menuOptions[i] << endl;
    }
    cout << "============" << endl;
}

int main()
{
    EmployeeList empList;
    //CWageEmployee wagie = CWageEmployee();
    //wagie.setName("Lajos");
    //wagie.setHours(100);
    //wagie.setWage(50);
    //CWageEmployee wagie2 = CWageEmployee();
    //wagie2.setName("Géza");
    //wagie2.setHours(101);
    //wagie2.setWage(50);
    //CWageEmployee wagie3 = CWageEmployee();
    //wagie3.setName("Lajos");
    //wagie3.setHours(102);
    //wagie3.setWage(50);
    //empList.push_back(&wagie2);
    //empList.push_back(&wagie3);
    //empList.push_back(&wagie);

    int choice;
    bool validChoice = true;

    do {
        if (!validChoice) {
            cout << "Hibas valasztas, szamot irj, min 1 max " << optionSize << "." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
        displayMenu();
        cout << "Ird be a menupont szamat: ";
        cin >> choice;

        if (cin.fail() || choice <1 || choice > optionSize)
        {
            validChoice = false;
        }
        else
        {
            cout << menuOptions[choice - 1] << "t valasztottad" << endl;
            validChoice = true;
            switch (choice)
            {
            case 1:
                createEmployee(empList);
                break;
            case 2:
                listEmployees(empList);
                break;
            case 3:
                payByName(empList);
                break;
            case 4:
                listPays(empList, true);
                break;
            case 5:
                listPays(empList, false);
                break;
            }

        }
        cout << endl;
    } while (choice != optionSize);

    cout << "Kilepes..." << endl;

    for (auto emp : empList) {
        delete emp;
    }

    return 0;
}




//Osztályok:
/*
CEmployee
    m_szName
CWageEmployee 
    m_fHours
    m_fWage
CSalesPerson
    m_fSalesMade
    m_fCommission
CManager
    m_fWeeklySalary
    
void Input(void): bevitel
float ComputePay(void) fizetés számítása
void Display(void) megjelenít

menü:
1.Bevitel : tesztadatok bevitele (típus megadása!), nem a konstruktorban! (vf)
2.Lista : felvitel sorrendje szerint, megjelenítendő adatok: név, további adatok (vf)
3.Fizetés : adott dolgozó (név alapján) fizetése a név bekérése után: név, majd a fizetés megjelenítése (vf)
4.Fizetés szerint csökkenő lista, átlagfizetés: fizetés szerint csökkenő sorrendben, és a végén a dolgozók átlagfizetése külön sorban. 
Megjelenítendő adatok: sorszám, fizetés, név, további adatok (vf) és a végén az átlag
5.Fizetés szerint növekvő lista, átlagfizetés: fizetés szerint növekvő sorrendben, és a végén a dolgozók átlagfizetése külön sorban.
Megjelenítendő adatok: sorszám, fizetés, név, további adatok (vf) és a végén az átlag
6. Kilépés
*/

