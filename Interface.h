//
// Created by sergio on 10/09/21.
//

#ifndef REWORKEDBANKACCOUNT_INTERFACE_H
#define REWORKEDBANKACCOUNT_INTERFACE_H
#include "User.h"

class Interface {
public:
    //main interface methods, allows access to the various operations
    bool startInterface();

    //prints to the screen the various action options the user has
    void printTextOptions();

    //methods to create User profile and multiple bank accounts
    void createBankAccount ();
    void createProfile ();

    //methods to get input
    static bool getStringInput (std:: string & input, int minLength = 0, int maxLength = 100);
    static bool getIntInput (int &input, int maxVal = 100000000, int minVal = 0);
    static void clear ();

    //method to check if input date is valid
    static bool isValidDate (tm *toCheck);
private:
    std:: unique_ptr<User> user;
};


#endif //REWORKEDBANKACCOUNT_INTERFACE_H
