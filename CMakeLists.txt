cmake_minimum_required(VERSION 3.10)
project(cppbase)

file(GLOB SOURCE "src/*.cpp")
file(GLOB HEADER "include/*.hpp")

set(CMAKE_CXX_STANDARD 17)

add_library(cppbase STATIC ${SOURCE})

add_executable(testcbase test/TestCBase.cpp)
target_link_libraries(testcbase cppbase)