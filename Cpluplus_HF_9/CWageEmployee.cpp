//JI9J9A Füzi Bálint FELADAT9V1
#include "CWageEmployee.h"
#include <iostream>

using namespace std;

class WageEmployee : public CEmployee {
public:
    void Input() override {
        CEmployee::Input();
        cout << "Add meg az orabert: ";
        cin >> m_fWage;
        cout << "Add meg a ledolgozott orakat: ";
        cin >> m_fHours;
    }

    float ComputePay() override {
        return m_fWage * m_fHours;
    }

    void Display() override {
        CEmployee::Display();
        cout << "Oraber: " << m_fWage << endl;
        cout << "Ledolgozott orak: " << m_fHours << endl;
    }

private:
    float m_fWage;
    float m_fHours;
};
