//JI9J9A Füzi Bálint FELADAT9V1
#include "CWageEmployee.h"
#include <iostream>

using namespace std;


void CWageEmployee::Input() {
    CEmployee::Input();
    cout << "Add meg az orabert: ";
    cin >> m_fWage;
    cout << "Add meg a ledolgozott orakat: ";
    cin >> m_fHours;
}

float CWageEmployee::ComputePay() {
    return m_fWage * m_fHours;
}

void CWageEmployee::Display() {
    CEmployee::Display();
    cout << "Oraber: " << m_fWage << endl;
    cout << "Ledolgozott orak: " << m_fHours << endl;
}

void CWageEmployee::setWage(const float wage)
{
    m_fWage = wage;
}

float CWageEmployee::getWage() const
{
    return m_fWage;
}

void CWageEmployee::setHours(const float hours)
{
    m_fHours = hours;
}

float CWageEmployee::getHours() const
{
    return m_fHours;
}
