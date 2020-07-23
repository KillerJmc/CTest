project(CTest)
set(CMAKE_CXX_STANDARD 20)
cmake_minimum_required(VERSION 3.16)


aux_source_directory(com/jmc/test/clms/cpp com_jmc_test_clms_src)
add_executable(CTest
        com/jmc/test/main/cpp/main.cpp
        com/jmc/io/cpp/file.cpp
        ${com_jmc_test_clms_src})

add_subdirectory(com/jmc/io)
include_directories(com/jmc/io/headers)
target_link_libraries(com_jmc_io)

add_subdirectory(com/jmc/test/clms)
include_directories(com/jmc/test/clms/headers)
target_link_libraries(com_jmc_test_clms)

add_subdirectory(com/jmc/test/main)
include_directories(com/jmc/test/main/headers)
target_link_libraries(com_jmc_test_main)