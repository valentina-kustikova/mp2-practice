set(target ${MP2_EXPRESSION_LIBRARY})

file(GLOB hdrs "*.h*" "${MP2_EXPRESSION_INCLUDE}/*.h*")
file(GLOB srcs "*.cpp")

include_directories("${MP2_EXPRESSION_INCLUDE}" "${MP2_LISTS_INCLUDE}" "${MP2_TPOLYNOMS_INCLUDE}")

add_library(${target} STATIC ${srcs} ${hdrs})
target_link_libraries(${target} ${MP2_LISTS_LIBRARY} ${MP2_TPOLYNOMS_LIBRARY})