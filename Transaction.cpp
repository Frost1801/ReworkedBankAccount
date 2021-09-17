//
// Created by sergio on 09/09/21.
//

#include "Transaction.h"

int Transaction::getValue() const {
    return value;
}

int Transaction::getType() const {
    return type;
}

const std::string &Transaction::getCause() const {
    return cause;
}

const std::string &Transaction::getTransactionMaker() const {
    return transactionMaker;
}

void Transaction::setDateAndTime(std::tm *toSet) {
    dateAndTime = toSet;
}

std:: tm *Transaction::getDateAndTime() const {
    return dateAndTime;
}

bool Transaction::areEqualDates(std:: tm * a, std :: tm * b) {
        if (a->tm_year == b->tm_year && a->tm_mon == b->tm_mon && a-> tm_mday == b-> tm_mday
            && a-> tm_hour == b-> tm_hour && a-> tm_min == b-> tm_min && a -> tm_sec == b-> tm_sec)
            return true;
        else
            return false;
}
