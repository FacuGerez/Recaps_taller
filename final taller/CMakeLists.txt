cmake_minimum_required(VERSION 3.15)

# Enable AUTOMOC for Qt's Meta-Object Compiler
set(CMAKE_AUTOMOC ON)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler flags for C and C++
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -pedantic -pedantic-errors -O0 -ggdb -DDEBUG -fno-inline -std=c11 -D _POSIX_C_SOURCE=200809L")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic -pedantic-errors -O0 -ggdb -DDEBUG -fno-inline -std=c++17 -D _POSIX_C_SOURCE=200809L")

# Add executables
add_executable(archivos ./archivos.cpp)
