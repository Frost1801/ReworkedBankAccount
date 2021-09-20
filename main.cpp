#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Transaction.h"
#include "BankAccount.h"
#include "User.h"
#include "Interface.h"

int main() {



    testing :: InitGoogleTest();
    return RUN_ALL_TESTS();


    Interface myInterface;
    while (myInterface.startInterface());


    return 0;
}
