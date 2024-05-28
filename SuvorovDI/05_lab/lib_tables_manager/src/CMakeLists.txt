set(target ${MP2_LIBRARY_MANAGER})

file(GLOB hdrs "*.h*" "${MP2_INCLUDE_MANAGER}/*.h*")
file(GLOB srcs "*.cpp")

include_directories("${MP2_INCLUDE_MANAGER}" "${MP2_INCLUDE_TABLES}" "${MP2_INCLUDE_POLYNOMS}" "${MP2_INCLUDE_LISTS}" )

add_library(${target} STATIC ${srcs} ${hdrs})

target_link_libraries(${target} ${MP2_LIBRARY_TABLES} ${MP2_LIBRARY_POLYNOMS} ${MP2_LIBRARY_LISTS})