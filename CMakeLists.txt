# init
project(CTest)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)
cmake_minimum_required(VERSION 3.16)

# set
set(ROOT src/com/jmc)
set(io ${ROOT}/io)
set(test_main ${ROOT}/test/main)
set(test_clms ${ROOT}/test/clms)
set(test_learn ${ROOT}/test/learn)

aux_source_directory(${io} io_src)
aux_source_directory(${test_main} test_main_src)
aux_source_directory(${test_clms} test_clms_src)
aux_source_directory(${test_learn} test_learn_src)

# include
include_directories(${io} ${test_main} ${test_clms} ${test_learn})

# add src
add_executable(CTest
        ${io_src}
        ${test_main_src}
        ${test_clms_src}
        ${test_learn_src}
)

# put the subdirs and create link libs
add_subdirectory(${io})
target_link_libraries(CTest com_jmc_io)

add_subdirectory(${test_main})
target_link_libraries(CTest com_jmc_test_main)

add_subdirectory(${test_clms})
target_link_libraries(CTest com_jmc_test_clms)

add_subdirectory(${test_learn})
target_link_libraries(CTest com_jmc_test_learn)