# add_compiler_args()
function(add_compiler_args)
	if (MSVC)
		# MSVC
		add_compile_options(/utf-8)

		# Link CRT if build type is Release
		if (CMAKE_BUILD_TYPE STREQUAL "Release")
			add_compile_options(/MT)
		endif()
	else()
		add_compile_options(
			-fno-stack-protector
			-fno-common
			-Wall
			-march=native
		)
		if (CMAKE_COMPILER_IS_GNUCXX)
			# GCC
			add_compile_options(
				-finput-charset=UTF8
				-fmax-errors=5
				$<$<STREQUAL:${CMAKE_GENERATOR},Ninja>:-fdiagnostics-color=always>
			)
		else()
			# Clang
			add_compile_options(
				-finput-charset=UTF-8
				-ferror-limit=5
				$<$<STREQUAL:${CMAKE_GENERATOR},Ninja>:-fcolor-diagnostics>
			)
		endif()
	endif()
endfunction()

# init_internal_args()
macro(init_internal_args)
	set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
endmacro()

