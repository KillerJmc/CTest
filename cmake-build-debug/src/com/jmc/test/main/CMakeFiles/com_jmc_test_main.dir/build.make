# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Programs\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Programs\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Programs\JetBrains\Projects\CProjects\CTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Programs\JetBrains\Projects\CProjects\CTest\cmake-build-debug

# Include any dependencies generated for this target.
include src\com\jmc\test\main\CMakeFiles\com_jmc_test_main.dir\depend.make

# Include the progress variables for this target.
include src\com\jmc\test\main\CMakeFiles\com_jmc_test_main.dir\progress.make

# Include the compile flags for this target's objects.
include src\com\jmc\test\main\CMakeFiles\com_jmc_test_main.dir\flags.make

src\com\jmc\test\main\CMakeFiles\com_jmc_test_main.dir\cpp\main.cpp.obj: src\com\jmc\test\main\CMakeFiles\com_jmc_test_main.dir\flags.make
src\com\jmc\test\main\CMakeFiles\com_jmc_test_main.dir\cpp\main.cpp.obj: ..\src\com\jmc\test\main\cpp\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Programs\JetBrains\Projects\CProjects\CTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/com/jmc/test/main/CMakeFiles/com_jmc_test_main.dir/cpp/main.cpp.obj"
	cd D:\Programs\JetBrains\Projects\CProjects\CTest\cmake-build-debug\src\com\jmc\test\main
	D:\Programs\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\com_jmc_test_main.dir\cpp\main.cpp.obj /FdCMakeFiles\com_jmc_test_main.dir\com_jmc_test_main.pdb /FS -c D:\Programs\JetBrains\Projects\CProjects\CTest\src\com\jmc\test\main\cpp\main.cpp
<<
	cd D:\Programs\JetBrains\Projects\CProjects\CTest\cmake-build-debug

src\com\jmc\test\main\CMakeFiles\com_jmc_test_main.dir\cpp\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/com_jmc_test_main.dir/cpp/main.cpp.i"
	cd D:\Programs\JetBrains\Projects\CProjects\CTest\cmake-build-debug\src\com\jmc\test\main
	D:\Programs\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe > CMakeFiles\com_jmc_test_main.dir\cpp\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Programs\JetBrains\Projects\CProjects\CTest\src\com\jmc\test\main\cpp\main.cpp
<<
	cd D:\Programs\JetBrains\Projects\CProjects\CTest\cmake-build-debug

src\com\jmc\test\main\CMakeFiles\com_jmc_test_main.dir\cpp\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/com_jmc_test_main.dir/cpp/main.cpp.s"
	cd D:\Programs\JetBrains\Projects\CProjects\CTest\cmake-build-debug\src\com\jmc\test\main
	D:\Programs\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\com_jmc_test_main.dir\cpp\main.cpp.s /c D:\Programs\JetBrains\Projects\CProjects\CTest\src\com\jmc\test\main\cpp\main.cpp
<<
	cd D:\Programs\JetBrains\Projects\CProjects\CTest\cmake-build-debug

src\com\jmc\test\main\CMakeFiles\com_jmc_test_main.dir\cpp\tools.cpp.obj: src\com\jmc\test\main\CMakeFiles\com_jmc_test_main.dir\flags.make
src\com\jmc\test\main\CMakeFiles\com_jmc_test_main.dir\cpp\tools.cpp.obj: ..\src\com\jmc\test\main\cpp\tools.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Programs\JetBrains\Projects\CProjects\CTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/com/jmc/test/main/CMakeFiles/com_jmc_test_main.dir/cpp/tools.cpp.obj"
	cd D:\Programs\JetBrains\Projects\CProjects\CTest\cmake-build-debug\src\com\jmc\test\main
	D:\Programs\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\com_jmc_test_main.dir\cpp\tools.cpp.obj /FdCMakeFiles\com_jmc_test_main.dir\com_jmc_test_main.pdb /FS -c D:\Programs\JetBrains\Projects\CProjects\CTest\src\com\jmc\test\main\cpp\tools.cpp
<<
	cd D:\Programs\JetBrains\Projects\CProjects\CTest\cmake-build-debug

src\com\jmc\test\main\CMakeFiles\com_jmc_test_main.dir\cpp\tools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/com_jmc_test_main.dir/cpp/tools.cpp.i"
	cd D:\Programs\JetBrains\Projects\CProjects\CTest\cmake-build-debug\src\com\jmc\test\main
	D:\Programs\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe > CMakeFiles\com_jmc_test_main.dir\cpp\tools.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Programs\JetBrains\Projects\CProjects\CTest\src\com\jmc\test\main\cpp\tools.cpp
<<
	cd D:\Programs\JetBrains\Projects\CProjects\CTest\cmake-build-debug

src\com\jmc\test\main\CMakeFiles\com_jmc_test_main.dir\cpp\tools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/com_jmc_test_main.dir/cpp/tools.cpp.s"
	cd D:\Programs\JetBrains\Projects\CProjects\CTest\cmake-build-debug\src\com\jmc\test\main
	D:\Programs\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\com_jmc_test_main.dir\cpp\tools.cpp.s /c D:\Programs\JetBrains\Projects\CProjects\CTest\src\com\jmc\test\main\cpp\tools.cpp
<<
	cd D:\Programs\JetBrains\Projects\CProjects\CTest\cmake-build-debug

# Object files for target com_jmc_test_main
com_jmc_test_main_OBJECTS = \
"CMakeFiles\com_jmc_test_main.dir\cpp\main.cpp.obj" \
"CMakeFiles\com_jmc_test_main.dir\cpp\tools.cpp.obj"

# External object files for target com_jmc_test_main
com_jmc_test_main_EXTERNAL_OBJECTS =

src\com\jmc\test\main\com_jmc_test_main.lib: src\com\jmc\test\main\CMakeFiles\com_jmc_test_main.dir\cpp\main.cpp.obj
src\com\jmc\test\main\com_jmc_test_main.lib: src\com\jmc\test\main\CMakeFiles\com_jmc_test_main.dir\cpp\tools.cpp.obj
src\com\jmc\test\main\com_jmc_test_main.lib: src\com\jmc\test\main\CMakeFiles\com_jmc_test_main.dir\build.make
src\com\jmc\test\main\com_jmc_test_main.lib: src\com\jmc\test\main\CMakeFiles\com_jmc_test_main.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Programs\JetBrains\Projects\CProjects\CTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library com_jmc_test_main.lib"
	cd D:\Programs\JetBrains\Projects\CProjects\CTest\cmake-build-debug\src\com\jmc\test\main
	$(CMAKE_COMMAND) -P CMakeFiles\com_jmc_test_main.dir\cmake_clean_target.cmake
	cd D:\Programs\JetBrains\Projects\CProjects\CTest\cmake-build-debug
	cd D:\Programs\JetBrains\Projects\CProjects\CTest\cmake-build-debug\src\com\jmc\test\main
	D:\Programs\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\link.exe /lib /nologo /machine:X86 /out:com_jmc_test_main.lib @CMakeFiles\com_jmc_test_main.dir\objects1.rsp 
	cd D:\Programs\JetBrains\Projects\CProjects\CTest\cmake-build-debug

# Rule to build all files generated by this target.
src\com\jmc\test\main\CMakeFiles\com_jmc_test_main.dir\build: src\com\jmc\test\main\com_jmc_test_main.lib

.PHONY : src\com\jmc\test\main\CMakeFiles\com_jmc_test_main.dir\build

src\com\jmc\test\main\CMakeFiles\com_jmc_test_main.dir\clean:
	cd D:\Programs\JetBrains\Projects\CProjects\CTest\cmake-build-debug\src\com\jmc\test\main
	$(CMAKE_COMMAND) -P CMakeFiles\com_jmc_test_main.dir\cmake_clean.cmake
	cd D:\Programs\JetBrains\Projects\CProjects\CTest\cmake-build-debug
.PHONY : src\com\jmc\test\main\CMakeFiles\com_jmc_test_main.dir\clean

src\com\jmc\test\main\CMakeFiles\com_jmc_test_main.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\Programs\JetBrains\Projects\CProjects\CTest D:\Programs\JetBrains\Projects\CProjects\CTest\src\com\jmc\test\main D:\Programs\JetBrains\Projects\CProjects\CTest\cmake-build-debug D:\Programs\JetBrains\Projects\CProjects\CTest\cmake-build-debug\src\com\jmc\test\main D:\Programs\JetBrains\Projects\CProjects\CTest\cmake-build-debug\src\com\jmc\test\main\CMakeFiles\com_jmc_test_main.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : src\com\jmc\test\main\CMakeFiles\com_jmc_test_main.dir\depend
