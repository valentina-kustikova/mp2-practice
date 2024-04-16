set(target ${MP2_XXH3_LIBRARY})

file(GLOB hdrs "*.h*" "${MP2_XXH3_INCLUDE}/*.h*")
file(GLOB srcs "*.c")

include_directories("${MP2_XXH3_INCLUDE}")

add_library(${target} STATIC ${srcs} ${hdrs})