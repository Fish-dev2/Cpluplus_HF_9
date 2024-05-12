//JI9J9A Füzi Bálint FELADAT9V1
#pragma once
#include "CWageEmployee.h"

class CSalesPerson : public CWageEmployee {
public:
    CSalesPerson();
    CSalesPerson(const std::string& name, float wage, float hours, float salesMade, float commission);
    void Input() override;
    float ComputePay() override;
    void Display() override;
    void setSalesMade(const float salesMade);
    float getSalesMade() const;
    void setCommission(const float commission);
    float getCommission() const;

private:
    float m_fSalesMade;
    float m_fCommission;
};

