//JI9J9A Füzi Bálint FELADAT9V1
#pragma once
#include <string>

class CEmployee {
public:
    virtual ~CEmployee() {}
    virtual void Input();
    virtual float ComputePay();
    virtual void Display();
    std::string getName() const;
    void setName(const std::string& name);
protected:
    std::string m_szName;
};


