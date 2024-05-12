//JI9J9A Füzi Bálint FELADAT9V1
#pragma once
#include <string>

class CEmployee {
public:
    CEmployee();
    CEmployee(const std::string& name);
    virtual ~CEmployee() {}
    virtual void Input();
    virtual float ComputePay() = 0;
    virtual void Display();
    std::string getName() const;
    void setName(const std::string& name);
protected:
    std::string m_szName;
};


