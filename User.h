//
// Created by sergio on 09/09/21.
//

#ifndef REWORKEDBANKACCOUNT_USER_H
#define REWORKEDBANKACCOUNT_USER_H
#include "BankAccount.h"

class User {
public:
    User (std:: string fullName, tm * dateOfBirth, std:: string address) : fullName(std:: move (fullName)), address(std:: move (address)) {
        this -> dateOfBirth = dateOfBirth;
        activeAccount = 0;
    }
    ~User();

    //basic banking operations
    void deposit (int depositValue, const std::string &cause);
    bool withdraw(int depositValue, const std::string &cause);
    bool transfer (int dest, int value, const std:: string & cause);
    bool moveTransaction(int transactionIndex, int accountIndex);
    void addTransaction (const Transaction &toAdd);
    bool removeTransaction (int index);


    //methods to switch and add bank accounts
    void addAccount (const std:: string& accountName);
    void switchAccount (int accountNumber);


    //methods to print to screen
    void printDepositHistory() const;
    void printWithdrawHistory() const;
    void printTransactionOfDate (std:: tm *dateOfTransaction) const;
    void printIndividualTransaction(const Transaction &it) const ;

    void printUserDetails () const;
    void printAccounts() const;

    //methods to read and write from file
    void generateReport () const;
    void readReport () const;
    static void clearFile (const std:: string & fileName);

    //getters
    tm *getDateOfBirth();
    [[nodiscard]] const std::vector<std::unique_ptr<BankAccount>> &getAccounts() const;
    [[nodiscard]] int getActiveAccount() const;

private:
    std:: string fullName;
    tm * dateOfBirth;
    std:: string address;
    std:: vector<std:: unique_ptr<BankAccount>> accounts;
    int activeAccount;
};


#endif //REWORKEDBANKACCOUNT_USER_H
