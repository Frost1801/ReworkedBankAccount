//
// Created by sergio on 10/09/21.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "User.h"

using testing :: Eq;

class TesterUser : public ::testing::Test {
public:
    std:: unique_ptr<User> tested;
    tm *date;
    TesterUser(){
        date = nullptr;
    }

    void SetUp () override {
        date = new tm;
        date->tm_year = 2000;
        date-> tm_mon = 1;
        date -> tm_mday = 1;
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


