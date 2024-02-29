set(target ${MP2_AE_LIBRARY})

file(GLOB hdrs "*.h*" "${MP2_AE_INCLUDE}/*.h*")
file(GLOB srcs "*.cpp")

include_directories("${MP2_AE_INCLUDE}")

add_library(${target} STATIC ${srcs} ${hdrs})
