//
// Created by sergio on 09/09/21.
//

#ifndef REWORKEDBANKACCOUNT_TRANSACTION_H
#define REWORKEDBANKACCOUNT_TRANSACTION_H
#include <iostream>
#include <ctime>
#include <utility>
#include <fstream>

const int DEPOSIT = 1;
const int WITHDRAW = 2;

class Transaction {
public:
    Transaction (int value, int type , std:: string transactionMaker, std:: string cause) :
    value(value), cause (std::move(cause)), transactionMaker(std::move(transactionMaker)), type (type){
        std::time_t t = std::time(nullptr);   // get time now
        dateAndTime = ctime(&t);
    }

    void print () const;

    int getValue() const;

    int getType() const;

    const std::string &getDateAndTime() const;

    const std::string &getCause() const;

    const std::string &getTransactionMaker() const;

private:
    int value;
    int type;
    std:: string dateAndTime;
    std:: string cause;
    std:: string transactionMaker;
};


#endif //REWORKEDBANKACCOUNT_TRANSACTION_H
