//JI9J9A Füzi Bálint FELADAT9V1
#include "CManager.h"
#include <iostream>

using namespace std;

void CManager::Input() {
    CEmployee::Input();
    cout << "Enter weekly salary: ";
    cin >> m_fWeeklySalary;
}

float CManager::ComputePay() {
    return m_fWeeklySalary;
}

void CManager::Display() {
    CEmployee::Display();
    cout << "Weekly Salary: " << m_fWeeklySalary << endl;
}
