//
// Created by sergio on 09/09/21.
//

#include "BankAccount.h"

void BankAccount::deposit(int depositValue, const std::string &profileName, const std::string &cause) {
    this -> balance += depositValue; //adds the depositValue to the balance
    this ->transactionHistory.push_back(std::make_unique<Transaction>(depositValue,DEPOSIT, profileName, cause)); //pushes the transaction to history vector
}

bool BankAccount::withdraw(int withdrawValue, const std::string &profileName, const std::string &cause) {
    if (this -> balance >= withdrawValue){ //checks if balance is bigger than withdraw value
        this -> balance -= withdrawValue; //reduces balance by withdrawValue
        this -> transactionHistory.push_back(std::make_unique<Transaction>(withdrawValue, WITHDRAW, profileName, cause)); //writes the transaction in the transaction list
        return true;
    }
    else {
        throw (std:: runtime_error ("Error, exceeding account balance (" + std:: to_string(this -> balance) + "$), please input a valid amount"));
    }
}



int BankAccount::getBalance() const {
    return balance;
}

const std::string &BankAccount::getName() const {
    return name;
}

std::vector<Transaction> BankAccount::getDepositTransactions() const {
    std:: vector<Transaction> toReturn;
    for (const auto & it : transactionHistory){
        if (it->getType() == DEPOSIT)
            toReturn.push_back(*(it));
    }
    return toReturn;
}

std::vector<Transaction> BankAccount::getWithdrawTransactions() const {
    std:: vector<Transaction> toReturn;
    for (const auto & it : transactionHistory){
        if (it->getType() == WITHDRAW)
            toReturn.push_back(*(it));
    }
    return toReturn;
}

std::vector<Transaction> BankAccount::getOfDateTransactions(std::tm *dateAndTime) const {
    std:: vector<Transaction> toReturn;
    for (const auto & it : transactionHistory){
        if (Transaction::areEqualDates(dateAndTime,it->getDateAndTime()))
            toReturn.push_back(*(it));
    }
    return toReturn;
}

Transaction BankAccount::removeTransaction(int index) {
    std:: unique_ptr <Transaction> tmp;
    tmp.swap (this -> transactionHistory.at(index-1));
    this -> transactionHistory.erase(transactionHistory.begin() + index - 1);
    return *tmp;
}

void BankAccount::addTransaction(const Transaction& toAdd) {
    this ->transactionHistory.push_back(std::make_unique<Transaction>(toAdd));
}


