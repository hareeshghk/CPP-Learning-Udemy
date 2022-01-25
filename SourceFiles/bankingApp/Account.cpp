#include <iostream>

#include "Account.h"

using namespace std;

int Account::s_ANGenerator = 1000;

Account::Account(const std::string &name, const float &balance): m_Name(name),
    m_Balance(balance) {
    cout << "Account()" << endl;
    
    m_AccNo = ++s_ANGenerator;
}

Account::~Account() {
    cout << "~Account()" << endl;
}

const std::string Account::GetName() const {
    return m_Name;
}

float Account::GetBalance() const {
    return m_Balance;
}

int Account::GetAccountNo() const {
    return m_AccNo;
}

void Account::AccumulateInterest() {
    cout << "Account accumulate" << endl;
}

void Account::Withdraw(float amount) {
    assert(amount>=0);

    if (m_Balance >= amount) {
        m_Balance -= amount;
    } else {
        cout << "Insufficient Balance to withdraw" << endl;
    }
}

void Account::Deposit(float amount) {
    assert(amount>=0);
    m_Balance += amount;
}

float Account::GetInterestRate() const {
    return 0.0f;
}