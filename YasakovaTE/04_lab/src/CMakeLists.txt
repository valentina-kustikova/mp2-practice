# Set target name
set(target ${01_LAB_POLYNOMS_LIBRARY})

# Get list of header and source files
FILE(GLOB hdrs "*.h" "${01_LAB_POLYNOMS_INCLUDE}/*.h")
FILE(GLOB srcs "*.cpp")

# Add a static library target to be built from the source
# files listed in the command invocation
ADD_LIBRARY(${target} STATIC ${srcs} ${hdrs})

# Specify include directories to use when compiling a target
TARGET_INCLUDE_DIRECTORIES(${target} PRIVATE ${01_LAB_POLYNOMS_INCLUDE})
