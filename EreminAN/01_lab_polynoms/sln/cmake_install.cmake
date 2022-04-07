# Install script for directory: C:/Users/Александр/Documents/GitHub/mp2-practice/EreminAN/01_lab_polynoms

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Polynomial")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/Александр/Documents/GitHub/mp2-practice/EreminAN/01_lab_polynoms/sln/List/cmake_install.cmake")
  include("C:/Users/Александр/Documents/GitHub/mp2-practice/EreminAN/01_lab_polynoms/sln/Monom/cmake_install.cmake")
  include("C:/Users/Александр/Documents/GitHub/mp2-practice/EreminAN/01_lab_polynoms/sln/Polynom/cmake_install.cmake")
  include("C:/Users/Александр/Documents/GitHub/mp2-practice/EreminAN/01_lab_polynoms/sln/main/cmake_install.cmake")
  include("C:/Users/Александр/Documents/GitHub/mp2-practice/EreminAN/01_lab_polynoms/sln/gtest/cmake_install.cmake")
  include("C:/Users/Александр/Documents/GitHub/mp2-practice/EreminAN/01_lab_polynoms/sln/test/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/Александр/Documents/GitHub/mp2-practice/EreminAN/01_lab_polynoms/sln/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
