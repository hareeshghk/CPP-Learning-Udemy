#pragma once
#include <string>

class Account {
    std::string m_Name;
    int m_AccNo;
    static int s_ANGenerator;
public:
    Account(const std::string &name, const float &balance);
    ~Account();
    const std::string GetName() const;
    float GetBalance() const;
    int GetAccountNo() const;

    void AccumulateInterest();
    void Withdraw(float amount);
    void Deposit(float amount);
    float GetInterestRate()const;
protected:
    float m_Balance;
};