set(target ${MP2_TABLE_LIBRARY})

file(GLOB hdrs "*.h*" "${MP2_TABLE_INCLUDE}/*.h*")
file(GLOB srcs "*.cpp")

include_directories("${MP2_TABLE_INCLUDE}")

add_library(${target} STATIC ${srcs} ${hdrs})

