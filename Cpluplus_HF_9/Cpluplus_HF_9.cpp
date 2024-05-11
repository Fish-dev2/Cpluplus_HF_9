
//JI9J9A Füzi Bálint FELADAT9V1
#include <iostream>
#include <limits>
#define MAXTEST = 10;
using namespace std;
const string menuOptions[] = { "Bevitel", "Lista", "Fizetes nev alapjan", "Fizetes csokkeno", "Fizetes novekvo", "Kilepes"};
const int optionSize = 6;



void displayMenu() {
    cout << "=== Menu ===" << endl;
    for (int i = 0; i < optionSize; ++i) {
        cout << i + 1 << ". " << menuOptions[i] << endl;

    }
    cout << "============" << endl;
}

int main()
{
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

