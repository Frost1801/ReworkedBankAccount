//
// Created by sergio on 09/09/21.
//

#include "User.h"
User::~User() {
    generateReport();
    readReport();
    delete dateOfBirth;
}

void User::printIndividualTransaction(const Transaction &it) const {
    std:: cout << std:: asctime (it .getDateAndTime())  << it . getTransactionMaker();
    if (it.getType() == DEPOSIT){
        std:: cout << " Deposited ";
    }
    else if (it.getType() == WITHDRAW){
        std:: cout << " Withdrawn ";
    }
    std:: cout << it . getValue() << "$" << std:: endl;
    std:: cout << "CAUSE: "<< it . getCause() << std:: endl;
}

void User::printDepositHistory() const { //prints all the transactions of the active account
    for (const auto & it : accounts){
        std:: vector<Transaction> deposits = it -> getDepositTransactions ();
        for (const auto & iter : deposits)
            printIndividualTransaction((iter));
    }
}

void User::printWithdrawHistory() const { //prints all the transactions of the active account
    for (const auto & it : accounts){
        std:: vector<Transaction> deposits = it -> getWithdrawTransactions();
        for (const auto & iter : deposits)
            printIndividualTransaction((iter));
    }
}

void User::printTransactionOfDate(std::tm *dateOfTransaction) const {
    for (const auto & it : accounts){
        std:: vector<Transaction> deposits = it -> getOfDateTransactions(dateOfTransaction);
        for (const auto & iter : deposits)
            printIndividualTransaction((iter));
    }
}

void User::printUserDetails() const { //prints user details to screen
    std:: cout << "DETAILS" << std:: endl;
    std:: cout<< "Name: " << fullName << std:: endl;
    std:: cout << "Date of birth: " << dateOfBirth->tm_mday << "/" << dateOfBirth->tm_mon + 1<< "/" << dateOfBirth->tm_year << std:: endl;
    std:: cout << "Address: " << address << std:: endl;
}

void User::deposit(int depositValue, const std::string &cause) {
    this -> accounts.at(activeAccount)->deposit(depositValue,this ->fullName,cause);
}

bool User::withdraw(int depositValue, const std::string &cause) {
    try{
        this -> accounts.at(activeAccount)->withdraw(depositValue,this ->fullName,cause);
    }
    catch (std:: runtime_error & e){
        std :: cout << e.what() << std:: endl;
        return false;
    }
    return true;
}

bool User::transfer(int dest, int value, const std::string &cause) {
    try{
        this -> accounts.at(activeAccount)->withdraw(value,this ->fullName,cause);
    }
    catch (std:: runtime_error & e){
        std :: cout << e.what() << std:: endl;
        return false;
    }
    this -> accounts.at(dest - 1)->deposit(value,this ->fullName,cause);
    return true;
}



void User::generateReport() const { //generates a report of the user activity on program shutdown and sends it to a file
    std:: ofstream report ("report.txt");
    report << "DETAILS" << std:: endl;
    report << "Name: " << fullName << std:: endl;
    report << "Date of birth: " << dateOfBirth->tm_mday << "/" << dateOfBirth->tm_mon + 1 << "/" << dateOfBirth->tm_year << std:: endl;
    report << "Address: " << address << std:: endl;

    int i = 1;
    for (auto & iter : accounts){
        report << std:: endl;
        report << "ACCOUNT N." << i << " - " << accounts.at(i-1)->getName();
        report << " - BALANCE: " << accounts.at(i - 1)->getBalance() << "$"<< std:: endl;
        report << "DEPOSITS:" << std:: endl;
        for (const auto & it : iter->getDepositTransactions()){
            report << std:: asctime (it .getDateAndTime()) << it . getTransactionMaker();
            report << " Deposited ";
            report << it . getValue() << "$" << std:: endl;
            report << "CAUSE: "<< it . getCause() << std:: endl;
        }
        report << "WITHDRAWS:" << std:: endl;
        for (const auto & it : iter->getWithdrawTransactions()){
            report << std:: asctime (it .getDateAndTime()) << it . getTransactionMaker();
            report << " Withdrawn ";
            report << it . getValue() << "$" << std:: endl;
            report << "CAUSE: "<< it . getCause() << std:: endl;
        }
        i++;
    }
}

void User::addAccount(const std::string& accountName) { //makes it possible to add another account
    accounts.push_back(std::make_unique<BankAccount>(accountName));
}

void User::switchAccount(int accountNumber) { //switches active account
    activeAccount = accountNumber - 1;
}

void User::readReport() const { //reads the activity report generated on program shutdown
    std::ifstream history ("report.txt");
    std:: string textLine;
    std:: cout << "USER REPORT:" << std:: endl;
    if (history.is_open())
        std::cout << history.rdbuf() << std:: endl;
}

void User::printAccounts() const { // prints all the accounts to screen
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

bool User::moveTransaction(int transactionIndex, int accountIndex) {
    try{
        Transaction tmp = this -> accounts.at(activeAccount)->removeTransaction(transactionIndex);
        this -> accounts.at(accountIndex-1)->addTransaction(tmp);
    }
    catch (std:: out_of_range &e){
        std:: cout << e.what() << std:: endl;
        return false;
    }
    return true;
}

void User::addTransaction(const Transaction &toAdd) {
    this -> accounts.at(activeAccount)->addTransaction(toAdd);
}

bool User::removeTransaction(int index) {
    try{
        this -> accounts.at(activeAccount)->removeTransaction(index);
    }
    catch (std:: out_of_range & e){
        std:: cout << e.what() << std:: endl;
        return false;
    }
    return true;
}



