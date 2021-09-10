cmake_minimum_required(VERSION 3.20)
project(ReworkedBankAccount)

set(CMAKE_CXX_STANDARD 20)

add_executable(ReworkedBankAccount main.cpp Transaction.cpp Transaction.h BankAccount.cpp BankAccount.h User.cpp User.h Interface.cpp Interface.h)
