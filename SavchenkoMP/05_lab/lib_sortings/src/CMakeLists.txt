set(target ${MP2_SORTINGS_LIBRARY})

file(GLOB hdrs "*.h*" "${MP2_SORTINGS_INCLUDE}/*.h*")
file(GLOB srcs "*.cpp")

include_directories("${MP2_SORTINGS_INCLUDE}")

add_library(${target} STATIC ${srcs} ${hdrs})