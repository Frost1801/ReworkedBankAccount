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
    //constructor
    //FIXME aggiungi la possibilità di mettere il tempo in input
    Transaction (int value, int type , std:: string transactionMaker, std:: string cause) :
    value(value), cause (std::move(cause)), transactionMaker(std::move(transactionMaker)), type (type){
        std::time_t t = std::time(nullptr);   // gets time of now
        dateAndTime = ctime(&t);
    }

    //overwritten == operator to compare two Transactions
    bool operator == (const Transaction& right){
        if (value == right.value && type == right.type && cause == right.cause && transactionMaker == right.transactionMaker)
            return true;
        else
            return false;
    }

    //method to print transaction information to screen
    void print () const;

    //getters
    [[nodiscard]] int getValue() const;
    [[nodiscard]] int getType() const;
    [[nodiscard]] const std::string &getDateAndTime() const;
    [[nodiscard]] const std::string &getCause() const;
    [[nodiscard]] const std::string &getTransactionMaker() const;

private:
    int value;
    int type;
    std:: string dateAndTime;
    std:: string cause;
    std:: string transactionMaker;
};


#endif //REWORKEDBANKACCOUNT_TRANSACTION_H
