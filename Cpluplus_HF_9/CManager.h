//JI9J9A Füzi Bálint FELADAT9V1
#pragma once
#include "CEmployee.h"

class CManager : public CEmployee {
public:
    void Input() override;
    float ComputePay() override;
    void Display() override;

private:
    float m_fWeeklySalary;
};

