//JI9J9A Füzi Bálint FELADAT9V1
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

std::string CEmployee::getName() const {
    return m_szName;
}

void CEmployee::setName(const std::string& name) {
    m_szName = name;
}