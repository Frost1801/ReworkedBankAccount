//
// Created by sergio on 10/09/21.
//

#include "Interface.h"
bool Interface::startInterface() {
     //user interface to access all the account's operations
        int input = 0;
        if (!user){ //checks if the user is already activated or not
            std:: cout << "Welcome, to make transactions you need to create a user profile"<< std:: endl;
            std:: cout << "Press (1) to create a user profile" << std:: endl ;
            std:: cout << "Press (0) to exit" << std:: endl;
            while (!(getIntInput(input, 2))); //takes an int to evaluate the choice

            if (input == 0){
                std:: cout << "Quitting..." << std:: endl;
                return false;
            }

            else if (input == 1)
                createProfile();
        }
        if (user -> getAccounts().empty()){ //checks if a bankAccount has already been created or not
            std:: cout << "To make transactions you need to create a bank account"<< std:: endl;
            std:: cout << "Press (1) to create an account" << std:: endl ;
            std:: cout << "Press (0) to exit" << std:: endl;
            while (!(getIntInput(input, 2))); //takes an int to evaluate the choice

            if (input == 0){
                std:: cout << "Quitting..." << std:: endl;
                return false;
            }

            else if (input == 1)
                createBankAccount();
        }
        printTextOptions();
        while (!(getIntInput(input, 6))); //gets input
        switch (input){
            case 1 : { //deposit option
                std:: cout << "Choose the amount you want to deposit, press (0) to cancel operation" << std:: endl;
                while (!(getIntInput(input)));
                if (input > 0){
                    std:: cout << "Please insert a cause for your operation: "<< std:: endl;
                    std:: string cause;
                    while (!getStringInput(cause)); //keeps asking for a username until a valid one is input
                    user -> deposit(input,cause);
                    std:: cout << "Deposited " << input << "$" << std:: endl;
                }
                break;
            }
            case 2:{ //withdraw option

                if (user -> getAccounts().at (user -> getActiveAccount())->getBalance() > 0) {
                    std:: cout << "Choose the amount you want to withdraw, press (0) to cancel operation" << std:: endl;
                    std:: string cause;
                    do{
                        while (!(getIntInput(input)));
                        std:: cout << "Please insert a cause for your operation: "<< std:: endl;
                        while (!getStringInput(cause)); //keeps asking for a cause until a valid one is input
                    }while (!(user->withdraw(input,cause)));
                    if (input > 0)
                        std:: cout << "Withdrawn " << input << "$" << std:: endl;
                }
                else {
                    std:: cout << "You haven't deposited any money yet!" << std:: endl;
                }

                break;
            }
            case 3: { //prints user details
                user ->printUserDetails();
                break;
            }
            case 4: { //print all account history option
                user -> printTransactionHistory();
                break;
            }
            case 5 : { //allows user to set a different account as active
                user->printAccounts();
                std:: cout << "Select the number of the account you want to set active, press (0) to exit" << std:: endl;
                while (!(getIntInput(input,user -> getAccounts().size() ))); //takes an int to evaluate the choice
                if (input != 0)
                    user ->switchAccount(input);
                break;
            }
            case 6 : { //allows User to create another bank account
                createBankAccount();
                break;
            }
            case 0 : { // quits the program
                std:: cout << "Quitting..." << std:: endl;

                return false;
            }
            default : {
                std:: cerr<< "Something went wrong (interface)" <<std:: endl;
                break;
            }
        }

        return true;

}
//FUNCTIONS TO GET INPUT

bool Interface ::getStringInput(std::string &input, int minLength, int maxLength) { //takes a string as input
    //performs various checks on that string, returns true if it passes, false otherwise
    try{
        std::getline(std:: cin,input);
        if (input.length() > maxLength){
            throw std:: out_of_range("String is bigger than maximum required length (" + std::to_string(maxLength) + ") chars");
        }
        if (input.length() < minLength){
            throw std:: out_of_range("String is smaller than minimum required length (" + std::to_string(minLength) + ") chars");
        }
    }
    catch (const std:: out_of_range & e){
        std:: cout << e.what()<< std:: endl;
        return false;
    }
    return true;
}

bool Interface ::getIntInput(int &input, int maxVal, int minVal) {//takes an int as input
    //performs various checks on the int, returns true if it passes, false otherwise
    try {
        std:: cin >> input;
        if (input < minVal)
            throw std:: out_of_range ("Input is smaller than minimum accepted value (" + std::to_string(minVal) +")");
        if (input > maxVal)
            throw std:: out_of_range ("Input exceeds the maximum number (" + std::to_string(maxVal) +")");
        if (input == 0)
            return true;
    }
    catch (const std:: out_of_range &e){
        std:: cout << e.what() << std:: endl;
        clear(); //clears the buffer
        return false;
    }
    clear(); //clears the buffer
    return true;
}

void Interface ::clear() { //clears input buffer, used in getIntInput
    std:: cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Interface ::printTextOptions() { //prints the interface options
    std:: cout << "Welcome to account N."<< user -> getActiveAccount() + 1;
    std:: cout << " - " << user ->getAccounts().at(user ->getActiveAccount())->getName();
    std:: cout << " - BALANCE: "<< user ->  getAccounts().at(user ->getActiveAccount())->getBalance() << "$"<< std:: endl;
    std:: cout << "Press (1) to deposit cash" << std:: endl;
    std:: cout << "Press (2) to withdraw cash" << std:: endl;
    std:: cout << "Press (3) to check your User information" << std:: endl;
    std:: cout << "Press (4) to check your account transactions history " << std:: endl;
    std:: cout << "Press (5) to change active account" << std:: endl;
    std:: cout << "Press (6) to create another bank account" << std:: endl;
    std:: cout << "Press (0) to quit and view session log" << std:: endl;
}
void Interface ::createBankAccount() {
    std:: cout << "Please insert a Name for your account: "<< std:: endl;
    std:: string inputName;
    while (!getStringInput(inputName, 5, 30)); //keeps asking for a username until a valid one is input
    user ->addAccount(inputName);
}


void Interface::createProfile() {
    std:: cout << "Please enter your full name: "<< std:: endl;
    std:: string inputName;
    while (!getStringInput(inputName, 5, 60)); //keeps asking for a username until a valid one is input
    std:: cout << "Please enter your home address: "<< std:: endl;
    std:: string address;
    while (!getStringInput(address, 5, 60)); //keeps asking for a username until a valid one is input
    tm * dateOfBirth = new tm;
    int counter = 0;
    do {
        if (counter != 0)
            std:: cout << "Invalid Date, please try again" << std:: endl;
        int day;
        std:: cout << "Please enter your day of birth (number)" << std:: endl;
        while (!(getIntInput(day, 31))); //takes an int to evaluate the choice
        int month;
        std:: cout << "Please enter your month of birth (number)" << std:: endl;
        while (!(getIntInput(month, 12))); //takes an int to evaluate the choice
        int year;
        std:: cout << "Please enter your year of birth (number)" << std:: endl;
        while (!(getIntInput(year))); //takes an int to evaluate the choice
        dateOfBirth->tm_mday = day;
        dateOfBirth -> tm_mon = month -1;
        dateOfBirth -> tm_year = year;
        counter ++;
    }while (!isValidDate(dateOfBirth));
    user = std::make_unique<User>(inputName,dateOfBirth,address);
}

bool Interface::isValidDate(tm *toCheck) { //checks if a date is valid
        if(1900 <= toCheck->tm_year && toCheck -> tm_year <= 2100)
        {
            int thirtyOneDaysM[7] = {0,2,4,6,7,9,11}; //31 days months
            for (int i : thirtyOneDaysM){
                if (toCheck->tm_mon == i){
                    if (toCheck -> tm_mday > 0 && toCheck -> tm_mday <=31)
                        return true;
                }
            }
            int thirtyDaysM[4] = {3,5,8,10};
            for (int i : thirtyDaysM){
                if (toCheck->tm_mon == i){
                    if (toCheck -> tm_mday > 0 && toCheck -> tm_mday <=30)
                        return true;
                }
            }
            if(toCheck -> tm_mon ==1)
            {
                if((toCheck-> tm_year%400==0 || (toCheck-> tm_year%100!=0 && toCheck-> tm_year%4==0)) && toCheck-> tm_mday>0 && toCheck-> tm_mday<=29)
                    return true;
                else if(toCheck-> tm_mday>0 && toCheck-> tm_mday<=28)
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
        else
            return false;
}
