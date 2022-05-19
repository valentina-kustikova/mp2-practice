# Set target name
set(target ${03_LAB_TREES_LIBRARY})

# Get list of header and source files
FILE(GLOB hdrs "*.h" "${03_LAB_TREES_INCLUDE}/*.h")
FILE(GLOB srcs "*.cpp")

# Add a static library target to be built from the source
# files listed in the command invocation
ADD_LIBRARY(${target} STATIC ${srcs} ${hdrs})

# Specify include directories to use when compiling a target
TARGET_INCLUDE_DIRECTORIES(${target} PRIVATE ${03_LAB_TREES_INCLUDE})
