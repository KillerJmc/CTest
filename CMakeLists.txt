project(CTest)
set(CMAKE_CXX_STANDARD 20)
cmake_minimum_required(VERSION 3.16)

include_directories(${PROJECT_SOURCE_DIR}/include)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
add_subdirectory(src)

#file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS src/*.cpp)
#add_library(_jmc ${SRCS})

#set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/modules)
#find_package(Jmc)
#if (JMC_FOUND)
#    include_directories(${JMC_INCLUDES})
#    add_executable(CTest src/com/jmc/test/main/main.cpp)
#    target_link_libraries(CTest ${JMC_LIBS})
#endif (JMC_FOUND)
