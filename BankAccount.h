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
    explicit BankAccount (std:: string name, int startingBalance = 0) : balance (startingBalance), name (std:: move (name)){};
    void deposit (int depositValue, const std:: string & profileName, const std:: string &cause);
    bool withdraw (int value, const std:: string & profileName, const std:: string &cause);

    const std::vector<std::unique_ptr<Transaction>> &getTransactionHistory() const;

    int getBalance() const;

    const std::string &getName() const;

private:
    std:: string name;
    int balance;
    std:: vector<std:: unique_ptr<Transaction>> transactionHistory;
};


#endif //REWORKEDBANKACCOUNT_BANKACCOUNT_H
