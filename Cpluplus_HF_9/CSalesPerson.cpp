//JI9J9A Füzi Bálint FELADAT9V1
#include "CSalesPerson.h"
#include <iostream>

using namespace std;

CSalesPerson::CSalesPerson()
{
}

CSalesPerson::CSalesPerson(const std::string& name, float wage, float hours, float salesMade, float commission)
    : CWageEmployee(name, wage, hours), m_fSalesMade(salesMade), m_fCommission(commission) {}

void CSalesPerson::Input() {
    CWageEmployee::Input();
    cout << "Add meg az eladasok szamat: ";
    cin >> m_fSalesMade;
    cout << "Add meg a jutalekot: ";
    cin >> m_fCommission;
}

float CSalesPerson::ComputePay() {
    return CWageEmployee::ComputePay() + m_fCommission * m_fSalesMade;
}

void CSalesPerson::Display() {
    CWageEmployee::Display();
    cout << "Eladasok: " << m_fSalesMade << endl;
    cout << "Jutalek: " << m_fCommission << endl;
}

void CSalesPerson::setSalesMade(const float salesMade)
{
    m_fSalesMade = salesMade;
}

float CSalesPerson::getSalesMade() const
{
    return m_fSalesMade;
}

void CSalesPerson::setCommission(const float commission)
{
    m_fCommission = commission;
}

float CSalesPerson::getCommission() const
{
    return m_fCommission;
}
