cmake_minimum_required(VERSION 3.10)
project(cppbase)

file(GLOB SOURCE "src/*.cpp")
file(GLOB HEADER "include/*.hpp")

set(CMAKE_CXX_STANDARD 17)

add_library(cppbase STATIC ${SOURCE})

#add_executable(test-baselib test/TestUDPServer.cpp)
#target_link_libraries(test-udp-server vika-net)
#
#add_executable(test-udp-client test/TestUDPClient.cpp)
#target_link_libraries(test-udp-client vika-net)
#
#add_executable(test-tcp-client test/TestTCPClient.cpp)
#target_link_libraries(test-tcp-client vika-net)