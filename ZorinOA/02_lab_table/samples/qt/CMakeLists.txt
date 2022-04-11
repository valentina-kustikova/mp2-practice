set(target ${02_LAB_TABLES_QT})

#set(CMAKE_PREFIX_PATH C:/Qt/6.3.0/msvc2019_64)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

FILE(GLOB hdrs "*.h")
FILE(GLOB srcs "*.cpp")
FILE(GLOB uics "*.ui")

ADD_EXECUTABLE(${target} ${uics} ${srcs} ${hdrs})

ADD_DEPENDENCIES(${target} ${02_LAB_TABLES_LIBRARY})

TARGET_LINK_LIBRARIES(${target} PRIVATE Qt6::Widgets ${02_LAB_TABLES_LIBRARY})

set_target_properties(${target} PROPERTIES WIN32_EXECUTABLE TRUE)

TARGET_INCLUDE_DIRECTORIES(${target} PRIVATE ${02_LAB_TABLES_INCLUDE})

qt_finalize_executable(${target})
