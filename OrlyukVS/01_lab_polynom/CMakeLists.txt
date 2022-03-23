cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(Polynoms)

include(cmake/function.cmake)

add_subdirectory(include)

add_subdirectory(src)
add_subdirectory(samples)

option(BTEST "build test?" ON)

if(BTEST)
    add_subdirectory(gtest)
    add_subdirectory(test)
endif()