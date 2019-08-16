/**
 * Liam Floyd
 * 10/26/17
 * Lab 8
 */
#include "Account.h"
#include "CertificateOfDeposit.h"

// Constructor
CertificateOfDeposit::CertificateOfDeposit(int newAccountNum) {
    accountNum = newAccountNum;
    hasWithdrawn = false;
    type = "Certificate of Deposit";
}

// Applies an interest rate to the balance
void CertificateOfDeposit::accrueInterest() {
    if(hasWithdrawn)
        balance *= 1.01;
    else
        balance *= 1.10;
}

// Removes money from the bank account
void CertificateOfDeposit::withdrawal(float amount) {
    balance -= amount;
    hasWithdrawn = true;

}
