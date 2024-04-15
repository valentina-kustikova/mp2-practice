set(target ${POLYNOMIALS_LIBRARY})

file(GLOB hdrs "*.h*" "${POLYNOMS_INCLUDE}/*.h*")
file(GLOB srcs "*.cpp")

include_directories("${LISTS_INCLUDE}" "${POLYNOMS_INCLUDE}")

add_library(${target} STATIC ${srcs} ${hdrs})
target_link_libraries(${target} ${LISTS_LIBRARY})