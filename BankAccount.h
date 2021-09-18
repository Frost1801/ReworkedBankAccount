//
// Created by sergio on 09/09/21.
//

#ifndef REWORKEDBANKACCOUNT_BANKACCOUNT_H
#define REWORKEDBANKACCOUNT_BANKACCOUNT_H
#include <vector>
#include <memory>
#include "Transaction.h"

class BankAccount {
public:
    //constructor
    explicit BankAccount (std:: string name, int startingBalance = 0) : balance (startingBalance), name (std:: move (name)){};

    //basic account operations
    void deposit (int depositValue, const std:: string & profileName, const std:: string &cause);
    bool withdraw (int value, const std:: string & profileName, const std:: string &cause);
    void addTransaction (const Transaction& toAdd);
    Transaction removeTransaction(int index);

    //getters
    [[nodiscard]] std:: vector <Transaction> getDepositTransactions () const;
    [[nodiscard]] std:: vector <Transaction> getWithdrawTransactions () const;
    [[nodiscard]] std:: vector <Transaction> getOfDateTransactions (std:: tm * dateAndTime) const;
    


    [[nodiscard]] int getBalance() const;
    [[nodiscard]] const std::string &getName() const;


private:
    std:: string name; //BankAccount name
    int balance; //balance of the account
    std:: vector<std:: unique_ptr<Transaction>> transactionHistory; //transactions that happened in the account
};


#endif //REWORKEDBANKACCOUNT_BANKACCOUNT_H
