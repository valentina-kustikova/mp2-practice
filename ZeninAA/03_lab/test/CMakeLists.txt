set(target ${MP2_TESTS})

file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${target} ${srcs} ${hdrs} "test_list.cpp" "test_list_stack.cpp")
target_link_libraries(${target} gtest ${MP2_LIBRARY})
