cmake_minimum_required(VERSION 3.7)


set(PROJECT_NAME 05_lab)
project(${PROJECT_NAME})

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE})

set(MP2_TABLES_LIBRARY "${PROJECT_NAME}_tables")
set(MP2_SORTINGS_LIBRARY "${PROJECT_NAME}_sortings")
set(MP2_XXH3_LIBRARY "${PROJECT_NAME}_xxh3")
set(MP2_TESTS   "tests_${PROJECT_NAME}")

set(MP2_TABLES_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/lib_tables/include")
set(MP2_SORTINGS_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/lib_sortings/include")
set(MP2_XXH3_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/lib_xxh3/include")

# BUILD
add_subdirectory(samples)
add_subdirectory(gtest)
add_subdirectory(tests)
add_subdirectory(lib_tables/src)
add_subdirectory(lib_sortings/src)
add_subdirectory(lib_xxh3/src)

# REPORT
message( STATUS "")
message( STATUS "General configuration for ${PROJECT_NAME}")
message( STATUS "=================================================")
message( STATUS "")
message( STATUS "   Configuration:           ${CMAKE_BUILD_TYPE}")
message( STATUS "   ----------------------------------------------")
message( STATUS "   Library names")
message( STATUS "   MP2_TABLES_LIBRARY:      ${MP2_TABLES_LIBRARY}")
message( STATUS "   MP2_SORTINGS_LIBRARY:    ${MP2_SORTINGS_LIBRARY}")
message( STATUS "   MP2_XXH3_LIBRARY:        ${MP2_XXH3_LIBRARY}")
message( STATUS "   ----------------------------------------------")
message( STATUS "   Test project name")
message( STATUS "   MP2_TESTS:               ${MP2_TESTS}")
message( STATUS "   ----------------------------------------------")
message( STATUS "   Include directories")
message( STATUS "   MP2_TABLES_INCLUDE:      ${MP2_TABLES_INCLUDE}")
message( STATUS "   MP2_SORTINGS_INCLUDE:    ${MP2_SORTINGS_INCLUDE}")
message( STATUS "   MP2_XXH3_INCLUDE:        ${MP2_XXH3_INCLUDE}")
message( STATUS "=================================================")
message( STATUS "")
