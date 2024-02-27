set(target ${MP2_PREFIXFORM_LIBRARY})

file(GLOB hdrs "*.h*" "${MP2_PREFIXFORM_INCLUDE}/*.h*")
file(GLOB srcs "*.cpp")

include_directories("${MP2_PREFIXFORM_INCLUDE}")

add_library(${target} STATIC ${srcs} ${hdrs})
