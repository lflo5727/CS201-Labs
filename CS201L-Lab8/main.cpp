/**
 * Liam Floyd
 * 10/26/17
 * Lab 8
 */

#include "Account.h"
#include "CertificateOfDeposit.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <fstream>
using namespace std;

int main() {
    // File I/O
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    // Stores up to 30 accounts
    Account* accounts[30];
    // Number of accounts that have been opened
    int numAccounts = 0;

    // For file input processing
    string command, acctType;
    int acctNum1, acctNum2;
    double amount;

    // Do the input and math
    while(fin >> command) {
        if(command == "NEW") {
            fin >> acctType >> acctNum1;
            if(acctType == "CHECKING"){
                accounts[numAccounts] = new CheckingAccount(acctNum1);
            }else if(acctType == "SAVINGS"){
                accounts[numAccounts] = new SavingsAccount(acctNum1);
            }else if(acctType == "CERTIFICATE"){
                accounts[numAccounts] = new CertificateOfDeposit(acctNum1);
            }
            numAccounts++;
            // Create a new account
        }
        else if (command == "WITHDRAWAL") {
            fin >> acctNum1 >> amount;
            for(int p = 0; p < numAccounts;p++){
                if(acctNum1 == accounts[p]->getAccountNum()){
                    accounts[p]->withdrawal(amount);
                    break;
                }
            }
            // Remove money from an account
        }
        else if (command == "DEPOSIT") {
            fin >> acctNum1 >> amount;
            for(int p = 0; p < numAccounts;p++){
                if(acctNum1 == accounts[p]->getAccountNum()){
                    accounts[p]->deposit(amount);
                    break;
                }
            }
            // Add money to an account
        }
        else if (command == "TRANSFER") {
            fin >> acctNum1 >> acctNum2 >> amount;
            for(int p = 0; p < numAccounts;p++){
                if(acctNum1 == accounts[p]->getAccountNum()){
                    accounts[p]->withdrawal(amount);
                    break;
                }
            }
            for(int q = 0; q < numAccounts;q++){
                if(acctNum2 == accounts[q]->getAccountNum()){
                    accounts[q]->deposit(amount);
                    break;
                }
            }
            // Move money from one account to another
        }
        else if (command == "INTEREST") {
            for(int i = 0; i < numAccounts; i++){
                accounts[i]->accrueInterest();
            }

            // Calculate interest on all accounts
        }
    }

    // Print output
    fout << "BANK STATEMENT" << endl << endl;

    for(int i = 0; i < numAccounts; i++) {
        fout << "Account number: " << accounts[i]->getAccountNum() << endl;
        fout << "Type of account: " << accounts[i]->getAccountType() << endl;
        fout << "Balance: $" << accounts[i]->getBalance() << endl;
        fout << endl;
    }

    // Delete accounts
    for (int i = 0; i < numAccounts; i++) {
        delete accounts[i];
    }

    // Close file streams
    fin.close();
    fout.close();

    return 0;
}
