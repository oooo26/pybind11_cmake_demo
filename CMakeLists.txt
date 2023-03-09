cmake_minimum_required(VERSION 3.10)
project(pybind_demo LANGUAGES CXX)

# environment variables
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

if(MSVC)
    SET(CMAKE_CXX_FLAGS "/EHsc /arch:AVX2")
    SET(CMAKE_CXX_FLAGS_DEBUG "/W4")
elseif(DARWIN)
    SET(CMAKE_CXX_FLAGS "-Wno-int-in-bool-context -std=c++11")
    SET(CMAKE_CXX_FLAGS_DEBUG "-Wall")
else()
    SET(CMAKE_CXX_FLAGS "-march=native -Wno-int-in-bool-context -std=c++11 -mavx -mfma")
    SET(CMAKE_CXX_FLAGS_DEBUG "-Wall")
endif()

# dependencies
find_package(pybind11)
find_package(OpenMP)

# sources
SET(SOURCES
    src/demo.cpp
)
add_library(pybind_demo MODULE ${SOURCES})

# links
target_include_directories(pybind_demo PRIVATE include
                                                 src)
target_link_libraries(pybind_demo PRIVATE pybind11::module 
                                            pybind11::opt_size 
                                            pybind11::lto
                                            pybind11::windows_extras)
if(OpenMP_CXX_FOUND)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    target_link_libraries(pybind_demo PRIVATE OpenMP::OpenMP_CXX)
endif()

# build extension
pybind11_extension(pybind_demo)
pybind11_strip(pybind_demo)

set_target_properties(pybind_demo PROPERTIES CXX_VISIBILITY_PRESET "hidden"
                                               CUDA_VISIBILITY_PRESET "hidden")
