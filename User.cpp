//
// Created by sergio on 09/09/21.
//

#include "User.h"
User::~User() {
    generateReport();
    readReport();
    delete dateOfBirth;
}


void User::printTransactionHistory() const {
    {
        for (const auto & it : accounts.at(activeAccount)->getTransactionHistory()){
             it->print();
        }
    }
}

void User::printUserDetails() const {
    std:: cout << "DETAILS" << std:: endl;
    std:: cout<< "Name: " << fullName << std:: endl;
    std:: cout << "Date of birth: " << dateOfBirth->tm_mday << "/" << dateOfBirth->tm_mon << "/" << dateOfBirth->tm_year << std:: endl;
    std:: cout << "Address: " << address << std:: endl;
}

void User::deposit(int depositValue, const std::string &cause) {
    this -> accounts.at(activeAccount)->deposit(depositValue,this ->fullName,cause);
}

bool User::withdraw(int depositValue, const std::string &cause) {
    return this -> accounts.at(activeAccount)->withdraw(depositValue,this ->fullName,cause);
}




void User::generateReport() const {
    std:: ofstream report ("report.txt");
    report << "DETAILS" << std:: endl;
    report << "Name: " << fullName << std:: endl;
    report << "Date of birth: " << dateOfBirth->tm_mday << "/" << dateOfBirth->tm_mon + 1 << "/" << dateOfBirth->tm_year << std:: endl;
    report << "Address: " << address << std:: endl;

    int i = 1;
    for (auto & iter : accounts){
        report << std:: endl;
        report << "ACCOUNT N." << i << " - " << accounts.at(getActiveAccount())->getName();
        report << " - BALANCE: " << accounts.at(getActiveAccount())->getBalance() << "$"<< std:: endl;
        for (const auto & it : iter->getTransactionHistory()){
            report << it ->getDateAndTime() << it -> getTransactionMaker();
            if (it-> getType() == DEPOSIT){
                report << " Deposited ";
            }
            else if (it->getType() == WITHDRAW){
                report << " Withdrawn ";
            }
            report << it -> getValue() << "$" << std:: endl;
            report << "CAUSE: "<< it -> getCause() << std:: endl;
        }

        i++;
    }
}

void User::addAccount(const std::string& accountName) {
    accounts.push_back(std::make_unique<BankAccount>(accountName));
}

void User::switchAccount(int accountNumber) {
    activeAccount = accountNumber - 1;
}

void User::readReport() const {
    std::ifstream history ("report.txt");
    std:: string textLine;
    std:: cout << "USER REPORT:" << std:: endl;
    if (history.is_open())
        std::cout << history.rdbuf() << std:: endl;
}

void User::printAccounts() const {
    int i = 1;
    for (const auto & it: accounts){
        std:: cout << i << ") " << it ->getName() << " - " << it -> getBalance() <<  "$" << std:: endl;
        i++;
    }
}

tm *User::getDateOfBirth() {
    return dateOfBirth;
}

const std::vector<std::unique_ptr<BankAccount>> &User::getAccounts() const {
    return accounts;
}

int User::getActiveAccount() const {
    return activeAccount;
}

void User::clearFile(const std::string &fileName) {
    std:: ofstream toClear;
    toClear.open(fileName, std:: fstream::out | std:: fstream::trunc); //trunc deletes any contents that existed in the file before it is open
    toClear.close();
}


