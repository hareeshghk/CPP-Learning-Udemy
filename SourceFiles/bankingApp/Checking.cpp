#include <iostream>

#include "Checking.h"

// Checking::Checking(const std::string &name, const float &balance):Account(name, balance) {
// }

Checking::~Checking() {
}

void Checking::Withdraw(float amount) {
    if (m_Balance - amount < 50) {
        std::cout << "Minimum Balance should be 50 in Checking Account" << std::endl;
        return;
    }
    Account::Withdraw(amount);
}