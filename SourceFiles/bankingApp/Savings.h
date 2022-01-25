#pragma once
#include "Account.h"

class Savings: public Account {
private:
    float m_Rate;
public:
    Savings(const std::string &name, const float &balance, const float &rate);
    ~Savings();
    void AccumulateInterest() override;
    float GetInterestRate()const override;
};
