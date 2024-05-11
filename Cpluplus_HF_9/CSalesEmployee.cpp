//JI9J9A Füzi Bálint FELADAT9V1
#include "CSalesEmployee.h"
#include <iostream>

using namespace std;

void CSalesEmployee::Input() {
    CWageEmployee::Input();
    cout << "Enter sales made: ";
    cin >> m_fSalesMade;
    cout << "Enter commission: ";
    cin >> m_fCommission;
}

float CSalesEmployee::ComputePay() {
    return CWageEmployee::ComputePay() + m_fCommission * m_fSalesMade;
}

void CSalesEmployee::Display() {
    CWageEmployee::Display();
    cout << "Sales Made: " << m_fSalesMade << endl;
    cout << "Commission: " << m_fCommission << endl;
}
