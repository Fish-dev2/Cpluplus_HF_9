#include "CEmployee.h"
#include <iostream>

using namespace std;

void CEmployee::Input() {
    cout << "Add meg a dolgozo nevet: ";
    cin >> m_szName;
}

float CEmployee::ComputePay() {
    return 0.0f;
}

void CEmployee::Display() {
    cout << "Nev: " << m_szName << endl;
}