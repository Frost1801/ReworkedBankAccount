//
// Created by sergio on 09/09/21.
//

#include "BankAccount.h"

void BankAccount::deposit(int depositValue, const std::string &profileName, const std::string &cause) {
    this -> balance += depositValue; //adds the depositValue to the balance
    this ->transactionHistory.push_back(std::make_unique<Transaction>(depositValue,DEPOSIT, profileName, cause)); //pushes the transaction to history vector
}

bool BankAccount::withdraw(int withdrawValue, const std::string &profileName, const std::string &cause) {
    if (this -> balance >= withdrawValue){
        this -> balance -= withdrawValue;
        this -> transactionHistory.push_back(std::make_unique<Transaction>(withdrawValue, WITHDRAW, profileName, cause));
        return true;
    }
    else {
        std::cout << "Error, exceeding account balance (" <<  this -> balance << "$)"<< std:: endl;
        return false;
    }
}

const std::vector<std::unique_ptr<Transaction>> &BankAccount::getTransactionHistory() const {
    return transactionHistory;
}
