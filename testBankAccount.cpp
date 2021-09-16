//
// Created by sergio on 10/09/21.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "BankAccount.h"

using testing :: Eq;

class TesterBankAccount : public ::testing::Test {
public:
    std:: unique_ptr<BankAccount> tested;
    TesterBankAccount(){
        tested = std::make_unique<BankAccount>("test");
    }
};

TEST_F(TesterBankAccount, depositTest){
    EXPECT_EQ (0,tested->getBalance());
    tested ->deposit(100,"test", "test cause");
    ASSERT_EQ(100, tested-> getBalance());
}

TEST_F(TesterBankAccount, withdrawTest){
    EXPECT_EQ (0,tested->getBalance());
    tested ->deposit(100,"test", "test cause");
    tested ->withdraw(100,"test", "test cause");
    ASSERT_EQ(0, tested-> getBalance());
}

TEST_F (TesterBankAccount, withdrawValidTest){ //checks basic withdraw function action
    tested->deposit(100, "test", "test cause");
    tested->withdraw(100, "test", "test cause");
    ASSERT_EQ(0, tested -> getBalance());
}

//FIXME QUANDO È INVALIDA SIA LANCIATA UNA ECCEZIONE E QUI VERIFICHIAMO IL LANCIO DELL'ECCEZIONE
TEST_F (TesterBankAccount, withdrawInvalidTest){ //checks if the withdrawal is activated even with insufficient balance
    tested ->deposit(100, "test", "test cause");
    tested->withdraw(101, "test", "test cause");
    ASSERT_EQ(100, tested -> getBalance());
}

TEST_F (TesterBankAccount, withdrawReturnTrue){ //checks return value in the case of a successful withdrawal
    tested ->deposit(100, "test", "test cause");
    ASSERT_EQ(true, tested -> withdraw (100, "test", "test cause"));
}
TEST_F (TesterBankAccount, withdrawReturnFalse){ //checks return value in the case of a failed withdrawal
    tested ->deposit(100, "test", "test cause");
    ASSERT_EQ(false, tested -> withdraw (101, "test", "test cause"));
}


TEST_F (TesterBankAccount, transactionHistoryTest){
    tested->getTransactionHistoryNonConst().clear();
    tested ->deposit(100, "test", "test cause");
    //creates a transaction that shall be equal to the one in the first slot of the vector
    Transaction mustBeEqual (100,DEPOSIT, "test", "test cause");
    bool status;
    //FIXME TOGLIERE IL METODO CHE RENDE TUTTA LA TRANSACTION HISTORY
    //TODO INSERIRE TUTTO IN UN SOLO ASSERT EQUAL
    if (mustBeEqual == *(tested-> getTransactionHistory().at(0)))
        status = true;
    else
        status = false;
    ASSERT_EQ(true, status);
}
