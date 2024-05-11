//JI9J9A Füzi Bálint FELADAT9V1
#include <iostream>
#include <limits>
#include <vector>

#include "CWageEmployee.h"
#include "CSalesEmployee.h"
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

    CEmployee* emp = nullptr;
    switch (choice) {
        case 1: {
            emp = new CWageEmployee();
            break;
        }
        case 2: {
            emp = new CSalesEmployee();
            break;
        }
        case 3: {
            emp = new CManager();
            break;
        }
        default: {
            cout << "Hibas valasztas. Letrehozas megszakitva." << endl;
            return;
        }
    }
    emp->Input();
    empList.push_back(emp);
}
void listEmployees(const EmployeeList& empList) {
    if (empList.empty()) {
        cout << "Meg nem adtal hozza employeet" << endl;
        return;
    }

    cout << "Employee lista:" << endl;
    for (size_t i = 0; i < empList.size(); ++i) {
        cout << "Employee " << i + 1 << ":" << endl;
        empList[i]->Display();
        cout << endl;
    }
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
            switch (choice)
            {
            case 1:
                createEmployee(empList);
                break;
            case 2:
                listEmployees(empList);
                break;
            }

        }
        cout << endl;
    } while (choice != optionSize);

    cout << "Kilepes..." << endl;


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

