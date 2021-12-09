cmake_minimum_required(VERSION 3.10)
project(heap VERSION 1.0)

SET(CMAKE_BUILD_TYPE distribution)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -O3 -lgmpxx -lgmp -fopenmp")
MESSAGE("Arch: " ${ARCH})
MESSAGE("Using compiler: " ${CMAKE_CXX_COMPILER})
MESSAGE("Using GCC Options: " ${CMAKE_CXX_FLAGS_DISTRIBUTION})
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.71.0 COMPONENTS timer) 
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
configure_file (
  "${PROJECT_SOURCE_DIR}/HeapConfig.h.in"
  "${PROJECT_BINARY_DIR}/HeapConfig.h"
  )


add_subdirectory(Datastructures)
add_executable (heap AOC7.cpp)
# add the executable
#add_executable(heap main.cpp)
target_link_libraries(heap Datastructures gmpxx gmp "${Boost_LIBRARIES}")
target_include_directories(heap PUBLIC "${PROJECT_BINARY_DIR}"
                           "${Boost_INCLUDE_DIRS}"
                           "${PROJECT_SOURCE_DIR}/Datastructures")