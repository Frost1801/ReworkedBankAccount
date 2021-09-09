//
// Created by sergio on 09/09/21.
//

#include "Transaction.h"

void Transaction::print() const { //prints transaction details
    std:: cout << dateAndTime << transactionMaker;
    if (type == DEPOSIT){
        std:: cout << " Deposited ";
    }
    else if (type == WITHDRAW){
        std:: cout << " Withdrawn ";
    }
    std:: cout << value << "$" << std:: endl;
    std:: cout << "CAUSE: "<< cause << std:: endl;
}

int Transaction::getValue() const {
    return value;
}

int Transaction::getType() const {
    return type;
}

const std::string &Transaction::getDateAndTime() const {
    return dateAndTime;
}

const std::string &Transaction::getCause() const {
    return cause;
}

const std::string &Transaction::getTransactionMaker() const {
    return transactionMaker;
}
