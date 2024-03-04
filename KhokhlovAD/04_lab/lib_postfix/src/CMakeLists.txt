set(target ${MP2_POSTFIX_LIBRARY})

file(GLOB hdrs "*.h*" "${MP2_POSTFIX_INCLUDE}/*.h*")
file(GLOB srcs "*.cpp")

include_directories("${MP2_POSTFIX_INCLUDE}")

add_library(${target} STATIC ${srcs} ${hdrs})