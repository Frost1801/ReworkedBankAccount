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

    //getters
    [[nodiscard]] const std::vector<std::unique_ptr<Transaction>> &getTransactionHistory() const;
    [[nodiscard]] int getBalance() const;
    [[nodiscard]] const std::string &getName() const;
    std::vector<std::unique_ptr<Transaction>> &getTransactionHistoryNonConst();


private:
    std:: string name;
    int balance;
    std:: vector<std:: unique_ptr<Transaction>> transactionHistory;
};


#endif //REWORKEDBANKACCOUNT_BANKACCOUNT_H
