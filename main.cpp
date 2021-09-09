#include <iostream>
#include "Transaction.h"
#include "BankAccount.h"
#include "User.h"

int main() {
    tm *test = new tm;
    test -> tm_mday = 6;
    test->tm_year = 2001;
    test->tm_mon = 4;

    User giovanni ("Giovanni piero",test,"Via marconi 1");

    return 0;
}
