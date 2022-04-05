cmake_minimum_required(VERSION 3.16)
project(lab1)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(test/googletest-master)
include_directories(test/googletest-master/googletest/include)


add_executable(lab1 main.cpp LinkedList.cpp LinkedList.h Node.cpp Iterator.cpp ConstIterator.cpp Test.cpp)
target_link_libraries(lab1 gtest gtest_main)