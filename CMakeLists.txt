cmake_minimum_required(VERSION 3.0.0)
project(Sort VERSION 0.1.0)

# bring the headers
include_directories(Include)

# manually add the sources
# set(SOURCES Source/BubbleSort.cpp Source/Sort.cpp)
file(GLOB SOURCES "Source/*.cpp")

add_executable(Sort ${SOURCES})

