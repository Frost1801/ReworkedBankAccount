//
// Created by sergio on 09/09/21.
//

#include "User.h"
User::~User() {
    std:: ofstream report ("report.txt");
    report << "DETAILS" << std:: endl;
    report << "Name: " << fullName << std:: endl;
    report << "Date of birth: " << dateOfBirth->tm_mday << "/" << dateOfBirth->tm_mon << "/" << dateOfBirth->tm_year << std:: endl;
    report << "Address: " << address;
}


void User::printTransactionHistory() const {
    {
        for (const auto & it : accounts.at(activeAccount)->getTransactionHistory()){
             it->print();
        }
    }
}



void User::deposit(int depositValue, const std::string &cause) {
    this -> accounts.at(activeAccount)->deposit(depositValue,this ->fullName,cause);
}

bool User::withdraw(int depositValue, const std::string &cause) {
    return this -> accounts.at(activeAccount)->withdraw(depositValue,this ->fullName,cause);
}

void User::printUserDetails() const {
    std:: cout << "DETAILS" << std:: endl;
    std:: cout<< "Name: " << fullName << std:: endl;
    std:: cout << "Date of birth: " << dateOfBirth->tm_mday << "/" << dateOfBirth->tm_mon << "/" << dateOfBirth->tm_year << std:: endl;
    std:: cout << "Address: " << address;
}


