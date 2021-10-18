# CMakeList.txt : CMake project for Task6, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set (CMAKE_CXX_STANDARD 20)
project ("Task6")

enable_testing()
add_subdirectory(Tests)

# Add source to this project's executable.
add_executable (Task6 "Task6.cpp" "Task6.h" "List.h" "List.cpp" "someStruct.h")

# TODO: Add tests and install targets if needed.
