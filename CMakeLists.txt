cmake_minimum_required(VERSION 3.21)
project(OOP_ASSIGNMENT_2)

set(CMAKE_CXX_STANDARD 14)

include_directories("Bank System")

add_executable(OOP_ASSIGNMENT_2
        "Bank System/bank.cpp"
        "Bank System/bank.h"
        "Bank System/mainBank.cpp"
        "Bank System/users_data.txt")
