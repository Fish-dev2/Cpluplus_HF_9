//JI9J9A F�zi B�lint FELADAT9V1
#pragma once
#include "CEmployee.h"

class CWageEmployee : public CEmployee {
public:
    virtual ~CWageEmployee() {}
    void Input() override;
    float ComputePay() override;
    void Display() override;

protected:
    float m_fWage;
    float m_fHours;
};


