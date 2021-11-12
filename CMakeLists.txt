project(CTest)
set(CMAKE_CXX_STANDARD 23)
cmake_minimum_required(VERSION 3.20)

# 指定vs下为utf-8编码
add_compile_options("/utf-8")

# 设置exe输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 设置exe静态编译
set(CMAKE_EXE_LINKER_FLAGS -static)

# 导入jmc-libs库
include(${PROJECT_SOURCE_DIR}/modules/jmc-libs/install.cmake)

include_directories(
	${PROJECT_SOURCE_DIR}/include/clms
	${PROJECT_SOURCE_DIR}/include/test
)

set(COMPILE_ALL, false)

if (${COMPILE_ALL})
	file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS src/*.cpp)
	add_executable(CTest ${SRCS} src/main.cpp)
else()
	add_executable(CTest src/main.cpp)
endif()

