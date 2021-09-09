//
// Created by sergio on 09/09/21.
//

#include "Transaction.h"

void Transaction::print() const {
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
