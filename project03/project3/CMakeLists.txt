cmake_minimum_required(VERSION 3.14)
project(project3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(project3
    InfixToPostfix.cpp
    InfixToPostfix.hpp
    main.cpp
    Number.cpp
    Number.hpp
    SymbolTable.hpp
    Token.cpp
    Token.hpp
    TokenIterator.cpp
    TokenIterator.hpp
    Tokenizer.cpp
    Tokenizer.hpp)
