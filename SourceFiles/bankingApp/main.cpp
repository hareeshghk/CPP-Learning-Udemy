#include <iostream>

#include "Account.h"
#include "Savings.h"
#include "Checking.h"

int main() {
    Savings acc("Bob", 1000, 0.05);
    std::cout << "Initial Balance: " << acc.GetBalance() << std::endl;
    acc.Deposit(50.5);
    std::cout << "Current Balance: " << acc.GetBalance() << std::endl;
    acc.Withdraw(10.5);
    std::cout << "Current Balance: " << acc.GetBalance() << std::endl;
    std::cout << "Interest rate " << acc.GetInterestRate() << std::endl;
    acc.AccumulateInterest();
    std::cout << "Current Balance: " << acc.GetBalance() << std::endl;

    std::cout << "============" << std::endl;

    Checking acc2("Bob", 500);
    std::cout << "Initial Balance: " << acc2.GetBalance() << std::endl;
    acc2.Deposit(100);
    std::cout << "Current Balance: " << acc2.GetBalance() << std::endl;
    acc2.Withdraw(570);
    acc2.Withdraw(400);
    std::cout << "Current Balance: " << acc2.GetBalance() << std::endl;
    acc2.AccumulateInterest();
    std::cout << "Interest rate: " << acc2.GetInterestRate() << std::endl;
    
    return 0;
}