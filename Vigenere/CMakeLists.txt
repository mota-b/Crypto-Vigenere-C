cmake_minimum_required(VERSION 3.6)
project(Vigenere)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES code.cpp headers/chrypto.h functions/chrypto.cpp)
add_executable(Crypto_Sezar ${SOURCE_FILES})