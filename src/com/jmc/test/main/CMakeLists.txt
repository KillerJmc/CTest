set(CMAKE_EXE_LINKER_FLAGS -static)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(CTest main.cpp)

file(GLOB LIBS ${LIBRARY_OUTPUT_PATH}/*.a)
link_directories(${LIBRARY_OUTPUT_PATH})
target_link_libraries(CTest ${LIBS})


