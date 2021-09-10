//
// Created by sergio on 10/09/21.
//

#ifndef REWORKEDBANKACCOUNT_INTERFACE_H
#define REWORKEDBANKACCOUNT_INTERFACE_H
#include "User.h"

class Interface {
public:
    bool startInterface();

    void printTextOptions(); //prints to the screen the various action options the user hasy
    void createBankAccount ();

    void createProfile ();

    static bool getStringInput (std:: string & input, int minLength = 0, int maxLength = 100);
    static bool getIntInput (int &input, int maxVal = 100000000, int minVal = 0);
    static void clear ();

    bool isValidDate (tm *toCheck);
private:
    std:: unique_ptr<User> user;
};


#endif //REWORKEDBANKACCOUNT_INTERFACE_H
