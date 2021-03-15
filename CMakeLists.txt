cmake_minimum_required(VERSION 3.10)

# set project name
project(SinglyLinkedList VERSION 1.0)

# set the c++ standard
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED True)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

#include external library
FIND_PACKAGE(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#add files to project
add_library(${PROJECT_NAME} STATIC
    SinglyLinkedListLibrary.hpp
    SinglyLinkedListLibrary.cpp
    SinglyLinkedList.hpp
    SinglyLinkedList.cpp 
)

# add test executables
set(TEST_NAME ${PROJECT_NAME}Library_UnitTest)
add_executable(${TEST_NAME}
    SinglyLinkedListLibrary.hpp
    SinglyLinkedListLibrary.cpp
    SinglyLinkedList.hpp
    SinglyLinkedList.cpp 
    SinglyLinkedListLibraryAcceptanceTest.cpp
    SinglyLinkedListAcceptanceTest.cpp
)

target_link_libraries(${TEST_NAME} ${GTEST_LIBRARIES} pthread ${GTEST_MAIN_LIBRARIES} ${PROJECT_NAME})




