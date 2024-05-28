cmake_minimum_required(VERSION 3.7)

set(PROJECT_NAME tables)
project(${PROJECT_NAME})

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE})

set(MP2_TESTS "tests_${PROJECT_NAME}")

set(MP2_LIBRARY_TABLES "${PROJECT_NAME}")
set(MP2_INCLUDE_TABLES "${CMAKE_CURRENT_SOURCE_DIR}/lib_tables/include")

set(MP2_LIBRARY_LISTS "${PROJECT_NAME}_lists")
set(MP2_INCLUDE_LISTS "${CMAKE_CURRENT_SOURCE_DIR}/lib_tlist/include")

set(MP2_LIBRARY_POLYNOMS "${PROJECT_NAME}_polynoms")
set(MP2_INCLUDE_POLYNOMS "${CMAKE_CURRENT_SOURCE_DIR}/lib_tpolynom/include")

set(MP2_LIBRARY_MANAGER "${PROJECT_NAME}_manager")
set(MP2_INCLUDE_MANAGER "${CMAKE_CURRENT_SOURCE_DIR}/lib_tables_manager/include")

# BUILD
add_subdirectory(samples)
add_subdirectory(gtest)
add_subdirectory(tests)
add_subdirectory(lib_tables/src)
add_subdirectory(lib_tlist/src)
add_subdirectory(lib_tpolynom/src)
add_subdirectory(lib_tables_manager/src)

# REPORT
message( STATUS "" )
message( STATUS "General configuration for ${PROJECT_NAME}" )
message( STATUS "======================================" )
message( STATUS "" )
message( STATUS "   Configuration:        ${CMAKE_BUILD_TYPE}" )
message( STATUS "   MP2_LIBRARY_TABLES:   ${MP2_LIBRARY_TABLES}" )
message( STATUS "   MP2_TESTS:            ${MP2_TESTS}" )
message( STATUS "   MP2_INCLUDE_TABLES: ${MP2_INCLUDE_TABLES}" )
message( STATUS "======================================" )
message( STATUS "" )
