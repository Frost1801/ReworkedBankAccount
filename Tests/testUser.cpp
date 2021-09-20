//
// Created by sergio on 10/09/21.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../User.h"

using testing :: Eq;

class TesterUser : public ::testing::Test {
public:
    std:: unique_ptr<User> tested;
    std:: tm * date;
    TesterUser(){
        date = nullptr;
    }

    void SetUp () override {
        date = new std:: tm;
        date->tm_year = 100;
        date-> tm_mon = 1;
        date -> tm_mday = 1;
        date -> tm_hour = 10;
        date -> tm_min = 10;
        date -> tm_sec = 10;
        tested = std::make_unique<User>("test", date, "test address");
    }
};

TEST_F(TesterUser, activeAccountTest){
    int active = tested -> getActiveAccount();
    ASSERT_EQ(0, active);
}

TEST_F(TesterUser, addAccountTest){
    tested ->addAccount("addedAccount");
    ASSERT_EQ (tested-> getAccounts().size(), 1);
}

TEST_F(TesterUser, transferValidTest){ //checks if money is transferred successfully
    tested ->addAccount("account1");
    tested ->addAccount("account2");
    tested->getAccounts().at(0)->deposit(100,"testName","testCause");
    tested->transfer(2,100,"transfer");
    ASSERT_EQ(0,tested->getAccounts().at(0)->getBalance());
    ASSERT_EQ(100,tested->getAccounts().at(1)->getBalance());
}

TEST_F(TesterUser, transferInvalidTest){ //checks if transfer fails or not with input bigger than balance
    tested ->addAccount("account1");
    tested ->addAccount("account2");
    tested->getAccounts().at(0)->deposit(100,"testName","testCause");
    tested->transfer(2,101,"transfer");
    ASSERT_EQ(100,tested->getAccounts().at(0)->getBalance());
    ASSERT_EQ(0,tested->getAccounts().at(1)->getBalance());
}

TEST_F(TesterUser, transferReturnTrue){ //checks if transfer return true on a success
    tested ->addAccount("account1");
    tested ->addAccount("account2");
    tested->getAccounts().at(0)->deposit(100,"testName","testCause");
    bool outcome = tested->transfer(2,100,"transfer");
    ASSERT_TRUE(outcome);
}

TEST_F(TesterUser, transferReturnFalse){ //checks if transfer return false on a failure
    tested ->addAccount("account1");
    tested ->addAccount("account2");
    tested->getAccounts().at(0)->deposit(100,"testName","testCause");
    bool outcome = tested->transfer(2,101,"transfer");
    ASSERT_FALSE(outcome);
}

TEST_F(TesterUser, moveTransactionTest){ //checks if transaction is moved successfully
    Transaction t1 (100,DEPOSIT,"testUser","testCause");
    tested ->addAccount("account1");
    tested ->addAccount("account2");
    tested->addTransaction(t1);
    tested->moveTransaction(1,2);
    ASSERT_EQ(tested-> getAccounts().at(1)->getDepositTransactions().at(0), t1);
}

TEST_F(TesterUser, removeTransactionTest){
    Transaction t1 (100,DEPOSIT,"testUser","testCause");
    Transaction t2 (1000,DEPOSIT,"testUser","testCause");
    tested ->addAccount("account1");
    tested->addTransaction(t1);
    tested->addTransaction(t2);
    tested->removeTransaction(2);
    ASSERT_EQ(tested-> getAccounts().at(0)->getDepositTransactions().at(0), t1);
}



