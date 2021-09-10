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

    void deposit (int depositValue, const std::string &cause);
    bool withdraw(int depositValue, const std::string &cause);
    void addAccount (const std:: string& accountName);
    void switchAccount (int accountNumber);



    void printTransactionHistory () const;
    void printUserDetails () const;
    void printAccounts() const;

    void generateReport () const;
    void readReport () const;

    tm *getDateOfBirth();

    const std::vector<std::unique_ptr<BankAccount>> &getAccounts() const;

    int getActiveAccount() const;

private:
    std:: string fullName;
    tm * dateOfBirth;
    std:: string address;
    std:: vector<std:: unique_ptr<BankAccount>> accounts;
    int activeAccount;
};


#endif //REWORKEDBANKACCOUNT_USER_H
