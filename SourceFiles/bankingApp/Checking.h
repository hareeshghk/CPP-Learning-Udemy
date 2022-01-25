#pragma once
#include "Account.h"

class Checking: public Account {
public:
    using Account::Account;
    // commentong to use parent classes constructor.
    // Checking(const std::string &name, const float &balance);
    ~Checking();
    void Withdraw(float amount);
};
