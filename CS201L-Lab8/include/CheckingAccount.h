/**
 * Liam Floyd
 * 10/26/17
 * Lab 8
 */
#include "Account.h"

#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

class CheckingAccount : public Account{
    public:
        /**
         * Constructor
         * @param newAccountNum
         */
        CheckingAccount(int newAccountNum);

        /**
         * Applies an interest rate to the balance
         */
        void accrueInterest();
};

#endif //CHECKINGACCOUNT_H
