# Set target name
set(target "${03_LAB_TREES_TESTS}")

# Get list of header and source files
FILE(GLOB hdrs "*.h")
FILE(GLOB srcs "*.cpp")

# Add an executable to be built from the source
# files listed in the command invocation
ADD_EXECUTABLE(${target} ${srcs} ${hdrs})

# Specify include directories to use when compiling a target
TARGET_INCLUDE_DIRECTORIES(${target} PRIVATE ${GTEST_INCLUDE})
TARGET_INCLUDE_DIRECTORIES(${target} PRIVATE ${03_LAB_TREES_INCLUDE})

# Link a target to given libraries
TARGET_LINK_LIBRARIES(${target} gtest ${03_LAB_TREES_LIBRARY})
