/**
 * Liam Floyd
 * 10/26/17
 * Lab 8
 */
#include "Account.h"

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount : public Account{
    public:
        /**
         * Constructor
         * @param newAccountNum
         */
        SavingsAccount(int newAccountNum);

        /**
         * Applies an interest rate to the balance
         */
        void accrueInterest();
};

#endif  //SAVINGSACCOUNT_H

