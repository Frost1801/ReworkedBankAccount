//
// Created by sergio on 16/09/21.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Transaction.h"

using testing :: Eq;

class TesterTransaction : public ::testing::Test {
public:
    std:: unique_ptr<Transaction> tested;
    TesterTransaction(){
        tested = std::make_unique<Transaction>(0,DEPOSIT,"testUser","testCause");
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

TEST_F(TesterTransaction, constructorTimeSet){
    std:: unique_ptr <std:: tm> date = createDate();
    std:: unique_ptr<Transaction> tested = std::make_unique<Transaction>(0,DEPOSIT,"testUser","testCause",date.get());
    ASSERT_TRUE(Transaction :: areEqualDates(date.get(),tested->getDateAndTime()));
}
TEST_F(TesterTransaction, manualTimeSet){
    std:: unique_ptr <std:: tm> date = createDate();
    tested ->setDateAndTime(date.get());
    ASSERT_TRUE(Transaction :: areEqualDates(date.get(),tested->getDateAndTime()));
}