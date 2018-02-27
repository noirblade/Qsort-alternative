cmake_minimum_required(VERSION 3.9)
project(SuperQuickSortOperatorOL)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-O2")

add_executable(SuperQuickSort main.cpp SqSort.cpp SqSort.h CmpUnit.cpp CmpUnit.h)