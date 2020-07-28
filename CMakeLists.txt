# init
project(CTest)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)
cmake_minimum_required(VERSION 3.16)

# add src
aux_source_directory(src/com/jmc/io/cpp com_jmc_io_src)
aux_source_directory(src/com/jmc/test/main/cpp com_jmc_test_main_src)
aux_source_directory(src/com/jmc/test/clms/cpp com_jmc_test_clms_src)
aux_source_directory(src/com/jmc/test/learn/cpp com_jmc_test_learn_src)
add_executable(CTest
        ${com_jmc_io_src}
        ${com_jmc_test_main_src}
        ${com_jmc_test_clms_src}
        ${com_jmc_test_learn_src}
)

# put the subdirs, specify include dirs and create link libs
add_subdirectory(src/com/jmc/io)
include_directories(src/com/jmc/io/headers)
target_link_libraries(com_jmc_io)

add_subdirectory(src/com/jmc/test/clms)
include_directories(src/com/jmc/test/clms/headers)
target_link_libraries(com_jmc_test_clms)

add_subdirectory(src/com/jmc/test/main)
include_directories(src/com/jmc/test/main/headers)
target_link_libraries(com_jmc_test_main)

add_subdirectory(src/com/jmc/test/learn)
include_directories(src/com/jmc/test/learn/headers)
target_link_libraries(com_jmc_test_learn)