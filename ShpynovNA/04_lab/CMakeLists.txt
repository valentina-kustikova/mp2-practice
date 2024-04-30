cmake_minimum_required(VERSION 3.7)

set(PROJECT_NAME polynomial)
project(${PROJECT_NAME})

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(LISTS_LIBRARY "${PROJECT_NAME}_lists")
set(POLYNOMIALS_LIBRARY "${PROJECT_NAME}_polynoms")
set(TESTS "tests_${PROJECT_NAME}")
set(LISTS_INCLUDE "D:/GIT/mp2-practice/ShpynovNA/04_lab/list_libary/include")
set(POLYNOMS_INCLUDE "D:/GIT/mp2-practice/ShpynovNA/04_lab/polynomial_libary/include")

add_subdirectory(samples)
add_subdirectory(gtest)
add_subdirectory(tests)
add_subdirectory(list_libary/src)
add_subdirectory(polynomial_libary/src)