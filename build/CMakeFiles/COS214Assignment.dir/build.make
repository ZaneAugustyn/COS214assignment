# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cait/COS214assignment/COS214assignment-1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cait/COS214assignment/COS214assignment-1/build

# Include any dependencies generated for this target.
include CMakeFiles/COS214Assignment.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/COS214Assignment.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/COS214Assignment.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/COS214Assignment.dir/flags.make

CMakeFiles/COS214Assignment.dir/Waiter.cpp.o: CMakeFiles/COS214Assignment.dir/flags.make
CMakeFiles/COS214Assignment.dir/Waiter.cpp.o: ../Waiter.cpp
CMakeFiles/COS214Assignment.dir/Waiter.cpp.o: CMakeFiles/COS214Assignment.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cait/COS214assignment/COS214assignment-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/COS214Assignment.dir/Waiter.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/COS214Assignment.dir/Waiter.cpp.o -MF CMakeFiles/COS214Assignment.dir/Waiter.cpp.o.d -o CMakeFiles/COS214Assignment.dir/Waiter.cpp.o -c /home/cait/COS214assignment/COS214assignment-1/Waiter.cpp

CMakeFiles/COS214Assignment.dir/Waiter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/COS214Assignment.dir/Waiter.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cait/COS214assignment/COS214assignment-1/Waiter.cpp > CMakeFiles/COS214Assignment.dir/Waiter.cpp.i

CMakeFiles/COS214Assignment.dir/Waiter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/COS214Assignment.dir/Waiter.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cait/COS214assignment/COS214assignment-1/Waiter.cpp -o CMakeFiles/COS214Assignment.dir/Waiter.cpp.s

# Object files for target COS214Assignment
COS214Assignment_OBJECTS = \
"CMakeFiles/COS214Assignment.dir/Waiter.cpp.o"

# External object files for target COS214Assignment
COS214Assignment_EXTERNAL_OBJECTS =

libCOS214Assignment.a: CMakeFiles/COS214Assignment.dir/Waiter.cpp.o
libCOS214Assignment.a: CMakeFiles/COS214Assignment.dir/build.make
libCOS214Assignment.a: CMakeFiles/COS214Assignment.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cait/COS214assignment/COS214assignment-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libCOS214Assignment.a"
	$(CMAKE_COMMAND) -P CMakeFiles/COS214Assignment.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/COS214Assignment.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/COS214Assignment.dir/build: libCOS214Assignment.a
.PHONY : CMakeFiles/COS214Assignment.dir/build

CMakeFiles/COS214Assignment.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/COS214Assignment.dir/cmake_clean.cmake
.PHONY : CMakeFiles/COS214Assignment.dir/clean

CMakeFiles/COS214Assignment.dir/depend:
	cd /home/cait/COS214assignment/COS214assignment-1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cait/COS214assignment/COS214assignment-1 /home/cait/COS214assignment/COS214assignment-1 /home/cait/COS214assignment/COS214assignment-1/build /home/cait/COS214assignment/COS214assignment-1/build /home/cait/COS214assignment/COS214assignment-1/build/CMakeFiles/COS214Assignment.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/COS214Assignment.dir/depend

