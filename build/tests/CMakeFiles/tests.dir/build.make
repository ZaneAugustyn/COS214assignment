# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/xadrian/COS 214/GroupProject/COS214assignment"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/xadrian/COS 214/GroupProject/COS214assignment/build"

# Include any dependencies generated for this target.
include tests/CMakeFiles/tests.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/tests.dir/flags.make

tests/CMakeFiles/tests.dir/XadrianTesting.cpp.o: tests/CMakeFiles/tests.dir/flags.make
tests/CMakeFiles/tests.dir/XadrianTesting.cpp.o: ../tests/XadrianTesting.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/xadrian/COS 214/GroupProject/COS214assignment/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/tests.dir/XadrianTesting.cpp.o"
	cd "/home/xadrian/COS 214/GroupProject/COS214assignment/build/tests" && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/XadrianTesting.cpp.o -c "/home/xadrian/COS 214/GroupProject/COS214assignment/tests/XadrianTesting.cpp"

tests/CMakeFiles/tests.dir/XadrianTesting.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/XadrianTesting.cpp.i"
	cd "/home/xadrian/COS 214/GroupProject/COS214assignment/build/tests" && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/xadrian/COS 214/GroupProject/COS214assignment/tests/XadrianTesting.cpp" > CMakeFiles/tests.dir/XadrianTesting.cpp.i

tests/CMakeFiles/tests.dir/XadrianTesting.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/XadrianTesting.cpp.s"
	cd "/home/xadrian/COS 214/GroupProject/COS214assignment/build/tests" && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/xadrian/COS 214/GroupProject/COS214assignment/tests/XadrianTesting.cpp" -o CMakeFiles/tests.dir/XadrianTesting.cpp.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/XadrianTesting.cpp.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

tests/tests: tests/CMakeFiles/tests.dir/XadrianTesting.cpp.o
tests/tests: tests/CMakeFiles/tests.dir/build.make
tests/tests: lib/libgtest_main.a
tests/tests: libUnitTesting.a
tests/tests: lib/libgtest.a
tests/tests: tests/CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/xadrian/COS 214/GroupProject/COS214assignment/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tests"
	cd "/home/xadrian/COS 214/GroupProject/COS214assignment/build/tests" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/tests.dir/build: tests/tests

.PHONY : tests/CMakeFiles/tests.dir/build

tests/CMakeFiles/tests.dir/clean:
	cd "/home/xadrian/COS 214/GroupProject/COS214assignment/build/tests" && $(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/tests.dir/clean

tests/CMakeFiles/tests.dir/depend:
	cd "/home/xadrian/COS 214/GroupProject/COS214assignment/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/xadrian/COS 214/GroupProject/COS214assignment" "/home/xadrian/COS 214/GroupProject/COS214assignment/tests" "/home/xadrian/COS 214/GroupProject/COS214assignment/build" "/home/xadrian/COS 214/GroupProject/COS214assignment/build/tests" "/home/xadrian/COS 214/GroupProject/COS214assignment/build/tests/CMakeFiles/tests.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tests/CMakeFiles/tests.dir/depend
