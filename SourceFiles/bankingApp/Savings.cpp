#include "Savings.h"

Savings::Savings(const std::string &name, const float &balance, const float &rate):Account(name, balance),m_Rate(rate) {
}

Savings::~Savings() {
}

void Savings::AccumulateInterest() {
    m_Balance += (m_Balance*m_Rate);
}

float Savings::GetInterestRate() const {
    return m_Rate;
}