//JI9J9A F�zi B�lint FELADAT9V1
#pragma once
#include "CWageEmployee.h"

class CSalesEmployee : public CWageEmployee {
public:
    void Input() override;
    float ComputePay() override;
    void Display() override;

private:
    float m_fSalesMade;
    float m_fCommission;
};

