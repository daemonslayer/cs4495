cmake_minimum_required(VERSION 3.0)
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${ProjectId})
find_package(CUDA)
find_package(OpenCV REQUIRED )

file( GLOB  hdr *.hpp *.h )
file( GLOB  cu  *.cu)
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(NAME_SRC ps1.cpp)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

cuda_add_executable(${CMAKE_PROJECT_NAME} ${NAME_SRC} ${hdr} ${cu})
target_link_libraries(${CMAKE_PROJECT_NAME} ${OpenCV_LIBS})
