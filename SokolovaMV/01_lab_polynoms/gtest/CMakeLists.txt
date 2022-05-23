# Set target name
set(target "gtest")

# Get list of header and source files
FILE(GLOB hdrs "*.h")
FILE(GLOB srcs "*.cc")

# Add a static library target to be built from the source
# files listed in the command invocation
ADD_LIBRARY(${target} STATIC ${srcs} ${hdrs})

# Specify include directories to use when compiling a target
TARGET_INCLUDE_DIRECTORIES(${target} PRIVATE ${GTEST_INCLUDE})
