set(target ${TESTS})

file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

include_directories("${LISTS_INCLUDE}" "${POLYNOMS_INCLUDE}" "../gtest")

add_executable(${target} ${srcs} ${hdrs})
target_link_libraries(${target} gtest ${LISTS_LIBRARY} ${POLYNOMIALS_LIBRARY})	 