#include <iostream>

#include "Transaction.h"

using namespace std;

void Transact(Account *pAccount) {
    cout << "Starting transaction" << endl;
    cout << "Initial Balance: " << pAccount->GetBalance() << endl;
    pAccount->Withdraw(100);
    cout << "Current Balance: " << pAccount->GetBalance() << endl;
    pAccount->AccumulateInterest();
    cout << "Interset rate: " << pAccount->GetInterestRate() << endl;
    cout << "Current Balance: " << pAccount->GetBalance() << endl;
    return;
}