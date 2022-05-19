cmake_minimum_required(VERSION 3.5)

# Auxiluary info about the project
set(PROJECT_NAME)
PROJECT(${PROJECT_NAME} trees LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set configuration type (Debug or Release)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Set output directories for libraries and executables
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE})

# Set target names for libraries and executables
set(03_LAB_TREES_LIBRARY ${PROJECT_NAME})
set(03_LAB_TREES_SAMPLE "${PROJECT_NAME}_sample")
set(03_LAB_TREES_QT1 "${PROJECT_NAME}_qt1")
set(03_LAB_TREES_QT2 "${PROJECT_NAME}_qt2")
set(03_LAB_TREES_TESTS "${PROJECT_NAME}_test")

# Set additional include directories
set(03_LAB_TREES_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(GTEST_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/gtest")


# Add a subdirectory to the build (specify directories in which 
# the source CMakeLists.txt and code files are located)
add_subdirectory(gtest)
add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(samples)

# Report
message(STATUS "")
message(STATUS "General configuration for ${PROJECT_NAME} =====================================")
message(STATUS "")
message(STATUS "   Configuration:           ${CMAKE_BUILD_TYPE}")
message(STATUS "   Output directory:        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE}")
message(STATUS "   Library directory:       ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message(STATUS "===============================================================================")
