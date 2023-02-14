cmake_minimum_required(VERSION 2.5)

project(boost_thread)

message(STATUS "This is BINARY dir" ${PROJECT_BINARY_DIR})
message(STATUS "This is CMAKELIST dir" ${PROJECT_BINARY_DIR})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -lboost_thread -lboost_system")
#add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)

add_compile_options(-std=c++11 -fPIC -fdiagnostics-color=auto)

add_executable(boost_thread boost_thread.cpp)