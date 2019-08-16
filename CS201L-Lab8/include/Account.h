/**
 * Liam Floyd
 * 10/26/17
 * Lab 8
 */
#include <string>
using namespace std;

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
    protected:
        /**
         * The identifying number of the account
         */
        int accountNum;

        /**
         * The total amount of money stored in the account
         */
        double balance;

        /**
         * The type of account
         */
        string type;

    public:
        Account();

        /**
         * Returns the account number
         * @return
         */
        int getAccountNum();

        /**
         * Returns the account type
         * @return
         */
        string getAccountType();

        /**
         * Returns the amount of money stored
         * @return
         */
        double getBalance();

        /**
         * Applies an interest rate to the balance
         */
        virtual void accrueInterest() = 0;

        /**
         * Adds money to the bank account
         */
        virtual void deposit(double amount);

        /**
         * Removes money from the bank account
         */
        virtual void withdrawal(double amount);
};

#endif  //ACCOUNT_H
