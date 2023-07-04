cmake_minimum_required(VERSION 3.25)
project(text_management_sys)

set(CMAKE_CXX_STANDARD 17)

add_executable(text_management_sys main.cpp book.h textbooksource.cpp)
