# ÒýÈëjmc-libs
include(FetchContent)
FetchContent_Declare(
	JmcLibs
	GIT_REPOSITORY https://github.com/KillerJmc/jmc-libs
	GIT_TAG        2.0.0
)
FetchContent_MakeAvailable(JmcLibs)
link_libraries(JmcLibs::jmc-libs)

add_executable(main main.cpp)