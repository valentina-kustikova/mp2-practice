# Get all cpp-files in the current directory
file(GLOB samples_tables RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

foreach(sample_filename ${samples_tables})
  # Get file name without extension
  get_filename_component(sample ${sample_filename} NAME_WE)

  include_directories("${MP2_INCLUDE_TABLES}")

  # Add and configure executable file to be produced
  add_executable(${sample} ${sample_filename})
  target_link_libraries(${sample} ${MP2_LIBRARY_TABLES})
  set_target_properties(${sample} PROPERTIES
    OUTPUT_NAME "${sample}"
    PROJECT_LABEL "${sample}"
    RUNTIME_OUTPUT_DIRECTORY "../")
endforeach()

# set(sample_name ${QT_SAMPLE})

# # Укажите пути к заголовочным файлам
# include_directories("${MP2_INCLUDE_TABLES}")

# set(SOURCES
#   sample.cpp
#   MainWindow.cpp
# )

# set(HEADERS
#   MainWindow.h
# )

# add_executable(${sample_name} ${SOURCES} ${HEADERS})

# # Укажите зависимости для MOC (Meta-Object Compiler)
# qt6_wrap_cpp(MyQtApp_MOC MainWindow.h)
# target_sources(${sample_name} PRIVATE ${MyQtApp_MOC})

# # Подключите библиотеки
# target_link_libraries(${sample_name} Qt6::Core Qt6::Widgets Qt6::Gui ${MP2_LIBRARY_TABLES})

# # Указание директорий для поиска заголовочных файлов
# target_include_directories(${sample_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# set_target_properties(${sample} PROPERTIES
#     OUTPUT_NAME "${sample}"
#     PROJECT_LABEL "${sample}"
#     RUNTIME_OUTPUT_DIRECTORY "../")