# Get all cpp-files in the current directory
file(GLOB samples_tables RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

foreach(sample_filename ${samples_tables})
  # Get file name without extension
  get_filename_component(sample ${sample_filename} NAME_WE)

  include_directories("${MP2_INCLUDE_MANAGER}" "${MP2_INCLUDE_TABLES}" "${MP2_INCLUDE_POLYNOMS}" "${MP2_INCLUDE_LISTS}")

  # Add and configure executable file to be produced
  add_executable(${sample} ${sample_filename})
  target_link_libraries(${sample} ${MP2_LIBRARY_MANAGER} ${MP2_LIBRARY_TABLES} ${MP2_LIBRARY_POLYNOMS} ${MP2_LIBRARY_LISTS})
  set_target_properties(${sample} PROPERTIES
    OUTPUT_NAME "${sample}"
    PROJECT_LABEL "${sample}"
    RUNTIME_OUTPUT_DIRECTORY "../")
endforeach()