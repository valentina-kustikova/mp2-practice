file(GLOB samples_list RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

foreach(sample_filename ${samples_list})
  get_filename_component(sample ${sample_filename} NAME_WE)

  include_directories("${LISTS_INCLUDE}" "${POLYNOMS_INCLUDE}")

  add_executable(${sample} ${sample_filename})
  target_link_libraries(${sample} ${LISTS_LIBRARY} ${POLYNOMIALS_LIBRARY})
  set_target_properties(${sample} PROPERTIES
    OUTPUT_NAME "${sample}"
    PROJECT_LABEL "${sample}"
    RUNTIME_OUTPUT_DIRECTORY "../")
endforeach()