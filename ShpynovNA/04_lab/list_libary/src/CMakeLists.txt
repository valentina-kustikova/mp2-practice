set(target ${LISTS_LIBRARY})

file(GLOB hdrs "*.h*" "${LISTS_INCLUDE}/*.h*")
file(GLOB srcs "*.cpp")

include_directories("${LISTS_INCLUDE}" "${POLYNOMS_INCLUDE}")

add_library(${target} STATIC ${srcs} ${hdrs})