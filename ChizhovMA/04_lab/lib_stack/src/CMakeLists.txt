set(target ${MP2_STACK_LIBRARY})

file(GLOB hdrs "*.h*" "${MP2_STACK_INCLUDE}/*.h*")
file(GLOB srcs "*.cpp")

include_directories("${MP2_STACK_INCLUDE}")

add_library(${target} STATIC ${srcs} ${hdrs})
