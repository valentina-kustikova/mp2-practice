set(target ${03_LAB_TABLES_QT1})

set(CMAKE_PREFIX_PATH C:/Qt/6.3.0/msvc2019_64)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
qt_standard_project_setup()

FILE(GLOB hdrs "*.h")
FILE(GLOB srcs "*.cpp")
FILE(GLOB uics "*.ui")

ADD_EXECUTABLE(${target} ${uics} ${srcs} ${hdrs})

ADD_DEPENDENCIES(${target} ${03_LAB_TABLES_LIBRARY})

TARGET_LINK_LIBRARIES(${target} PRIVATE Qt6::Widgets ${03_LAB_TABLES_LIBRARY})

set_target_properties(${target} PROPERTIES WIN32_EXECUTABLE ON)

TARGET_INCLUDE_DIRECTORIES(${target} PRIVATE ${03_LAB_TABLES_INCLUDE})