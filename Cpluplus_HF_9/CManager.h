//JI9J9A Füzi Bálint FELADAT9V1
#pragma once
#include "CEmployee.h"

class CManager : public CEmployee {
public:
    CManager();
    CManager(const std::string& name, float weeklySalary);
    void Input() override;
    float ComputePay() override;
    void Display() override;
    float getWeeklySalary() const;
    void setWeeklySalary(const float weeklySalary);

private:
    float m_fWeeklySalary;
};

