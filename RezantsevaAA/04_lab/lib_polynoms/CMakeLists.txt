set(target ${MP2_POLYNOMS_LIBRARY})

file(GLOB hdrs "*.h*" "include/*.h*")
file(GLOB srcs "*.cpp" "src/*.cpp")

include_directories("${MP2_POLYNOMS_INCLUDE}" "${MP2_LISTS_INCLUDE}" )

add_library(${target} STATIC ${srcs} ${hdrs})
target_link_libraries(${target} ${MP2_LISTS_LIBRARY})