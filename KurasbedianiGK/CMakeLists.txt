cmake_minimum_required(VERSION 3.21)
project(mp2_lab4_polinoms)

set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -v")

include_directories(gtest)
include_directories(include)

add_executable(
        mp2_lab4_polinoms
        gtest/gtest-all.cc
        gtest/gtest.h
#        samples/main_polinom.cpp
        include/monom.h
        include/power.h
        include/node.h
        include/polynom.h
        include/list.h
        src/power.cpp
        src/monom.cpp
        test/test_power.cpp
        test/test_monom.cpp
        test/test_node.cpp
#        test/test_list.cpp
        test/test_polynom.cpp
        test/test_main.cpp
)