cmake_minimum_required (VERSION 3.8)

project (myTests)

include_directories(myTests "..")

add_executable (myTests Tests.cpp Tests.h ../List.h ../List.cpp)

add_test(NAME myTests COMMAND Tests)