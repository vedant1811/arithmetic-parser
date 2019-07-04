cmake_minimum_required(VERSION 3.5.0)

set(PROJECT_VERSION "0.5.10")
project(arithmetic-parser VERSION ${PROJECT_VERSION} LANGUAGES CXX)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories("${PROJECT_SOURCE_DIR}")

file(GLOB_RECURSE CPP_SOURCES ${PROJECT_SOURCE_DIR}/*.cpp)

add_library(parseLib ${CPP_SOURCES})

add_executable(parse ${PROJECT_SOURCE_DIR}/main.cpp)
target_link_libraries(parse parseLib)

# treat all warnings as errors 
target_compile_options(parseLib PRIVATE -Werror -Wall -Wextra)

# Setup CMake to run tests
enable_testing()

# Prep ourselves for compiling boost
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories (${Boost_INCLUDE_DIRS})

# Test files are in a separate source directory called test
file(GLOB_RECURSE TEST_SRCS RELATIVE ${CMAKE_SOURCE_DIR} test/*.cpp)

# Run through each source
foreach(testSrc ${TEST_SRCS})
    # Extract the filename without an extension (NAME_WE)
    get_filename_component(testName ${testSrc} NAME_WE)

    message("Adding test: ${testName}")

    # Add compile target
    add_executable(${testName} ${testSrc})

    # Link to Boost libraries, targets and dependencies
    target_link_libraries(${testName} ${Boost_LIBRARIES} parseLib)

    # Add it to test execution 
    add_test(NAME ${testName}
            COMMAND ${CMAKE_BINARY_DIR}/${testName})

endforeach(testSrc)
