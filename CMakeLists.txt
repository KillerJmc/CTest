# init
project(CTest)
set(CMAKE_CXX_STANDARD 20)
cmake_minimum_required(VERSION 3.16)

# add src
aux_source_directory(com/jmc/io/cpp com_jmc_io_src)
aux_source_directory(com/jmc/test/main/cpp com_jmc_test_main_src)
aux_source_directory(com/jmc/test/clms/cpp com_jmc_test_clms_src)
aux_source_directory(com/jmc/test/learn/cpp com_jmc_test_learn_src)
add_executable(CTest
        ${com_jmc_io_src}
        ${com_jmc_test_main_src}
        ${com_jmc_test_clms_src}
        ${com_jmc_test_learn_src}
)

# put the subdirs, specify include dirs and create link libs
add_subdirectory(com/jmc/io)
include_directories(com/jmc/io/headers)
target_link_libraries(com_jmc_io)

add_subdirectory(com/jmc/test/clms)
include_directories(com/jmc/test/clms/headers)
target_link_libraries(com_jmc_test_clms)

add_subdirectory(com/jmc/test/main)
include_directories(com/jmc/test/main/headers)
target_link_libraries(com_jmc_test_main)

add_subdirectory(com/jmc/test/learn)
include_directories(com/jmc/test/learn/headers)
target_link_libraries(com_jmc_test_learn)