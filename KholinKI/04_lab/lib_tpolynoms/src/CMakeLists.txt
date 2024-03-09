set(target ${MP2_TPOLYNOMS_LIBRARY})

file(GLOB hdrs "*.h*" "${MP2_TPOLYNOMS_INCLUDE}/*.h*")
file(GLOB srcs "*.cpp")

include_directories("${MP2_TPOLYNOMS_INCLUDE}" "${MP2_LISTS_INCLUDE}" "${MP2_EXPRESSION_INCLUDE}")

add_library(${target} STATIC ${srcs} ${hdrs})
target_link_libraries(${target} ${MP2_LISTS_LIBRARY})