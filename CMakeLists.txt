cmake_minimum_required(VERSION 3.12)
project(CTest LANGUAGES CXX VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(cmake/internal_utils.cmake)
add_compiler_args()
init_internal_args()

include_directories(include)

add_subdirectory(src)
