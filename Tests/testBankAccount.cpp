//
// Created by sergio on 10/09/21.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../BankAccount.h"


using testing :: Eq;

class TesterBankAccount : public ::testing::Test {
public:
    std:: unique_ptr<BankAccount> tested;
    TesterBankAccount(){
        tested = std::make_unique<BankAccount>("test");
    }
    std:: unique_ptr<std:: tm> createDate (){
        std:: unique_ptr <std:: tm> date = std::make_unique<tm>();
        date->tm_year = 100;
        date-> tm_mon = 1;
        date -> tm_mday = 1;
        date -> tm_hour = 10;
        date -> tm_min = 10;
        date -> tm_sec = 10;
        return date;
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


TEST_F (TesterBankAccount, withdrawInvalidTest){ //checks if the withdrawal is activated even with insufficient balance
    bool caught = false;
    tested ->deposit(100, "test", "test cause");
    try{
        tested->withdraw(101, "test", "test cause");
    }
    catch (std:: runtime_error & e) {
        caught = true;
    }
    ASSERT_TRUE(caught);
}

TEST_F (TesterBankAccount, withdrawReturnTrue){ //checks return value in the case of a successful withdrawal
    tested ->deposit(100, "test", "test cause");
    ASSERT_EQ(true, tested -> withdraw (100, "test", "test cause"));
}

TEST_F (TesterBankAccount, depositTransactionHistoryTest){ //checks if deposit transaction history works
    tested ->deposit(100, "test", "test cause");
    //creates a transaction that shall be equal to the one in the last slot of the vector
    Transaction mustBeEqual (100,DEPOSIT, "test", "test cause");
    ASSERT_EQ(mustBeEqual ,(tested-> getDepositTransactions().at(tested-> getDepositTransactions().size() - 1)));
}
TEST_F (TesterBankAccount, withdrawTransactionHistoryTest){ //checks if withdraw transaction history works
    tested ->deposit(100, "test", "test cause");
    //creates a transaction that shall be equal to the one in the last slot of the vector
    Transaction mustBeEqual (100,WITHDRAW, "test", "test cause");
    tested->withdraw(100, "test", "test cause");
    ASSERT_EQ(mustBeEqual ,(tested-> getWithdrawTransactions().at(tested-> getWithdrawTransactions().size() - 1)));
}

TEST_F (TesterBankAccount, datedTransactionHistory){ //creates a date and checks if the getter works for the added transaction of that date
    std:: unique_ptr <std:: tm> dateAndTime = createDate();
    //creates a transaction that shall be equal to the one in the last slot of the vector
    Transaction mustBeEqual (100,WITHDRAW, "test", "test cause",dateAndTime.get()); //creates a transaction with a set date
    tested->addTransaction(mustBeEqual);
    std:: vector <Transaction> ofDate = tested ->getOfDateTransactions(dateAndTime.get());
   ASSERT_EQ(ofDate.at(ofDate.size()-1).getDateAndTime(),std:: asctime(dateAndTime.get()));
}
TEST_F (TesterBankAccount, addRemoveTransactionTest){ //checks if adding and removing transactions works
    std:: unique_ptr <std:: tm> dateAndTime = createDate();
    //creates a transaction that shall be equal to the one in the first slot of the vector
    Transaction num1 (100,WITHDRAW, "test", "test cause",dateAndTime.get()); //creates a transaction from the set date
    Transaction num2 (100,WITHDRAW, "test", "test cause"); //creates a transaction with local time so num1 and num2 are different
    //add the transactions
    tested->addTransaction(num1);
    tested->addTransaction(num2);
    //removes the last transaction
    tested->removeTransaction(2);
    std:: vector <Transaction> withdraw = tested ->getWithdrawTransactions();
    ASSERT_EQ(num1 , withdraw.at(withdraw.size()-1));
}

