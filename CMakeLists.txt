cmake_minimum_required(VERSION 3.20)
project(ReworkedBankAccount)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(ReworkedBankAccount main.cpp Transaction.cpp Transaction.h BankAccount.cpp BankAccount.h User.cpp User.h Interface.cpp Interface.h Tests/testBankAccount.cpp Tests/testUser.cpp Tests/testTransaction.cpp)
target_link_libraries(ReworkedBankAccount gtest gtest_main)