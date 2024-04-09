set(target ${MP2_TESTS})


file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

include_directories("${MP2_TABLES_INCLUDE}" "${MP2_SORTINGS_INCLUDE}" "${MP2_XXH3_INCLUDE}" "../gtest")

add_executable(${target} ${srcs} ${hdrs})
target_link_libraries(${target} gtest ${MP2_TABLES_LIBRARY} ${MP2_SORTINGS_LIBRARY} ${MP2_XXH3_LIBRARY})
