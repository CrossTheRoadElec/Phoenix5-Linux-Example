# Project's name
PROJECT ( example C CXX )

# Specify the minimum version for CMake

cmake_minimum_required(VERSION 3.1)

add_definitions(-std=c++11)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package (Threads REQUIRED)
find_package(SDL2 REQUIRED)

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories(${SDL2_INCLUDE_DIRS})

link_directories("${PROJECT_SOURCE_DIR}/cpp/lib")

add_executable(example ${PROJECT_SOURCE_DIR}/example.cpp)

target_link_libraries(example ${CMAKE_SOURCE_DIR}/lib/x86-64/libCTRE_Phoenix.a)
target_link_libraries(example ${CMAKE_SOURCE_DIR}/lib/x86-64/libCTRE_PhoenixCCI.a)
target_link_libraries(example ${CMAKE_SOURCE_DIR}/lib/x86-64/libCTRE_PhoenixPlatform.a)
target_link_libraries(example ${CMAKE_SOURCE_DIR}/lib/x86-64/libCTRE_PhoenixCanutils.a)
target_link_libraries(example Threads::Threads)
target_link_libraries(example ${SDL2_LIBRARIES})
