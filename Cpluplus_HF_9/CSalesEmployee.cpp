//JI9J9A F�zi B�lint FELADAT9V1
#include "CSalesEmployee.h"
#include <iostream>

using namespace std;

void CSalesEmployee::Input() {
    CWageEmployee::Input();
    cout << "Add meg az eladasok szamat: ";
    cin >> m_fSalesMade;
    cout << "Add meg a jutalekot: ";
    cin >> m_fCommission;
}

float CSalesEmployee::ComputePay() {
    return CWageEmployee::ComputePay() + m_fCommission * m_fSalesMade;
}

void CSalesEmployee::Display() {
    CWageEmployee::Display();
    cout << "Eladasok: " << m_fSalesMade << endl;
    cout << "Jutalek: " << m_fCommission << endl;
}
