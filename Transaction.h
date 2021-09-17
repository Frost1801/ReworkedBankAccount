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
    Transaction (int value, int type , std:: string transactionMaker, std:: string cause) :
    value(value), cause (std::move(cause)), transactionMaker(std::move(transactionMaker)), type (type){
        std::time_t t = std::time(nullptr);   // gets time of now
        dateAndTime = localtime(&t);
    }
    //overloaded constructor to allow creation with a date as input
    Transaction (int value, int type , std:: string transactionMaker, std:: string cause, std:: tm *toSet) :
            value(value), cause (std::move(cause)), transactionMaker(std::move(transactionMaker)), type (type){
            dateAndTime = toSet;
    }

    //overloaded == operator to compare two Transactions
    bool operator == (const Transaction& right) const {
        if (value == right.value && type == right.type && cause == right.cause && transactionMaker == right.transactionMaker)
            return true;
        else
            return false;
    }

    static bool areEqualDates (std:: tm * a, std :: tm * b);

    //getters
    [[nodiscard]] int getValue() const;
    [[nodiscard]] int getType() const;
    [[nodiscard]] std:: tm *getDateAndTime() const;
    [[nodiscard]] const std::string &getCause() const;
    [[nodiscard]] const std::string &getTransactionMaker() const;


    //setters
    void setDateAndTime(std::tm *toSet); //allows setting custom date and time

private:
    int value;
    int type;
    std:: tm * dateAndTime; //date adn time represented as a tm struct from ctime
    std:: string cause;
    std:: string transactionMaker;
};


#endif //REWORKEDBANKACCOUNT_TRANSACTION_H
