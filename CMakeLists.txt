cmake_minimum_required(VERSION 3.7.0)

project(CLoCK-sensor LANGUAGES CXX)

find_package(PkgConfig)

find_package(OpenCV REQUIRED)

pkg_check_modules(LIBCAMERA REQUIRED IMPORTED_TARGET libcamera)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_library(CLoCK-sensor cameraInterface.h cameraInterface.cpp )

set_target_properties(CLoCK-sensor PROPERTIES CMAKE_POSITION_INDEPENDENT_CODE TRUE PUBLIC_HEADER "cameraInterface.h")

add_executable(optic-flow optic-flow.cpp)

target_link_libraries(CLoCK-sensor cam2opencv ${OpenCV_LIBS} pthread PkgConfig::LIBCAMERA)

target_link_libraries(optic-flow CLoCK-sensor)

set(CMAKE_BUILD_TYPE Debug)

add_compile_options(-Wall -pedantic)

install(TARGETS CLoCK-sensor)
