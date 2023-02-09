include(FetchContent)

# 引入jmc-libs
FetchContent_Declare(
	JmcLibs
	GIT_REPOSITORY https://github.com/KillerJmc/jmc-libs
	GIT_TAG        2.1.0
)
FetchContent_MakeAvailable(JmcLibs)
link_libraries(JmcLibs::jmc-libs)

# 引入boost
FetchContent_Declare(
	Boost
	GIT_REPOSITORY https://github.com/boostorg/boost
	GIT_TAG        boost-1.81.0
)
FetchContent_MakeAvailable(Boost)
link_libraries(Boost::serialization)

add_executable(main main.cpp)