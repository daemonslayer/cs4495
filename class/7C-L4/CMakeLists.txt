cmake_minimum_required(VERSION 2.8)
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
PROJECT(${ProjectId})
find_package(OpenCV REQUIRED )

set( NAME_SRC
    ${ProjectId}.cpp
)


INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable( ${CMAKE_PROJECT_NAME} ${NAME_SRC} ${NAME_HEADERS} )

target_link_libraries( ${CMAKE_PROJECT_NAME} ${OpenCV_LIBS} )
