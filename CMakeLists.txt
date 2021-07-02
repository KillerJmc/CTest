project(CTest)
set(CMAKE_CXX_STANDARD 20)
cmake_minimum_required(VERSION 3.19)

# 设置头文件路径
include_directories(
        ${PROJECT_SOURCE_DIR}/include/io
        ${PROJECT_SOURCE_DIR}/include/test
)

# 读取所有源文件
file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS src/*.cpp)

# 将源文件加入编译
add_executable(CTest ${SRCS})

# 设置exe静态编译
# set(CMAKE_EXE_LINKER_FLAGS -static)

# 设置exe输出路径
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 设置lib输出路径
# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 将源文件打包为库文件
# add_library(_jmc SHARED ${SRCS})


