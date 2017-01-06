cmake_minimum_required(VERSION 2.8)
PROJECT(ps1)
find_package(OpenCV REQUIRED )
set(CMAKE_CXX_FLAGS "-std=c++0x")

set( NAME_SRC
    ps1.cpp
)


INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable( ${CMAKE_PROJECT_NAME} ${NAME_SRC} ${NAME_HEADERS} )

target_link_libraries( ${CMAKE_PROJECT_NAME} ${OpenCV_LIBS} )
