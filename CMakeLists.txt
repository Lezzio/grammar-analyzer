cmake_minimum_required(VERSION 3.19)
project(TPCompil)

set(CMAKE_CXX_STANDARD 14)

add_executable(TPCompil Automate.cpp State.cpp Lexer.cpp Symbole.cpp main.cpp)