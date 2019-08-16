/**
 * Liam Floyd
 * 10/26/17
 * Lab 8
 */
#include "Account.h"

#ifndef CERTIFICATEOFDEPOSIT_H
#define CERTIFICATEOFDEPOSIT_H

class CertificateOfDeposit : public Account{
    private:
        /**
         *
         */
        bool hasWithdrawn;

    public:
        /**
         * Constructor
         * @param newAccountNum
         */
        CertificateOfDeposit(int newAccountNum);

        /**
         * Applies an interest rate to the balance
         */
        void accrueInterest();

        /**
         * Removes money from the bank account
         */
        void withdrawal(float amount);
};

#endif	//CERTIFICATEOFDEPOSIT_H
