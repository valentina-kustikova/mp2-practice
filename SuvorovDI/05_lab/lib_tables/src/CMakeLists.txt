set(target ${MP2_LIBRARY_TABLES})

file(GLOB hdrs "*.h*" "${MP2_INCLUDE_TABLES}/*.h*")
file(GLOB srcs "*.cpp")

include_directories("${MP2_INCLUDE_TABLES}")

add_library(${target} STATIC ${srcs} ${hdrs})
