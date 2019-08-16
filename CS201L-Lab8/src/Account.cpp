/**
 * Liam Floyd
 * 10/26/17
 * Lab 8
 */
#include "Account.h"


Account::Account() {
    balance = 0.0;
}

int Account::getAccountNum() {
    return accountNum;
}

string Account::getAccountType() {
    return type;
}

double Account::getBalance() {
    return balance;
}

void Account::deposit(double amount) {
    balance += amount;
}

void Account::withdrawal(double amount) {
    balance -= amount;
}
