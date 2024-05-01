cmake_minimum_required(VERSION 3.7.0)

project(CLoCK-vision LANGUAGES CXX)

find_package(OpenCV REQUIRED)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_library(CLoCK-vision cameraInterface.h cameraInterface.cpp)

set_target_properties(CLoCK-vision PROPERTIES CMAKE_POSITION_INDEPENDENT_CODE TRUE PUBLIC_HEADER "cameraInterface.h")

add_executable(optic-flow optic-flow.cpp)

target_link_libraries(CLoCK-vision cvCamera ${OpenCV_LIBS} pthread)

target_link_libraries(optic-flow CLoCK-vision)

set(CMAKE_BUILD_TYPE Debug)

add_compile_options(-Wall -pedantic)

install(TARGETS CLoCK-vision)
