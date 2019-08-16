/**
 * Liam Floyd
 * 10/26/17
 * Lab 8
 */
#include "Account.h"
#include "CheckingAccount.h"

// Constructor
CheckingAccount::CheckingAccount(int newAccountNum) {
    accountNum = newAccountNum;
    type = "Checking";

}

// Applies an interest rate to the balance
void CheckingAccount::accrueInterest() {
    //Checking accounts do not gain interest
}
