# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a

# Include any dependencies generated for this target.
include CMakeFiles/chlorine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/chlorine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chlorine.dir/flags.make

CMakeFiles/chlorine.dir/chlorine/src/chlorine.cpp.o: CMakeFiles/chlorine.dir/flags.make
CMakeFiles/chlorine.dir/chlorine/src/chlorine.cpp.o: chlorine/src/chlorine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chlorine.dir/chlorine/src/chlorine.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chlorine.dir/chlorine/src/chlorine.cpp.o -c /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a/chlorine/src/chlorine.cpp

CMakeFiles/chlorine.dir/chlorine/src/chlorine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chlorine.dir/chlorine/src/chlorine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a/chlorine/src/chlorine.cpp > CMakeFiles/chlorine.dir/chlorine/src/chlorine.cpp.i

CMakeFiles/chlorine.dir/chlorine/src/chlorine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chlorine.dir/chlorine/src/chlorine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a/chlorine/src/chlorine.cpp -o CMakeFiles/chlorine.dir/chlorine/src/chlorine.cpp.s

CMakeFiles/chlorine.dir/chlorine/src/chlorine.cpp.o.requires:

.PHONY : CMakeFiles/chlorine.dir/chlorine/src/chlorine.cpp.o.requires

CMakeFiles/chlorine.dir/chlorine/src/chlorine.cpp.o.provides: CMakeFiles/chlorine.dir/chlorine/src/chlorine.cpp.o.requires
	$(MAKE) -f CMakeFiles/chlorine.dir/build.make CMakeFiles/chlorine.dir/chlorine/src/chlorine.cpp.o.provides.build
.PHONY : CMakeFiles/chlorine.dir/chlorine/src/chlorine.cpp.o.provides

CMakeFiles/chlorine.dir/chlorine/src/chlorine.cpp.o.provides.build: CMakeFiles/chlorine.dir/chlorine/src/chlorine.cpp.o


# Object files for target chlorine
chlorine_OBJECTS = \
"CMakeFiles/chlorine.dir/chlorine/src/chlorine.cpp.o"

# External object files for target chlorine
chlorine_EXTERNAL_OBJECTS =

chlorine: CMakeFiles/chlorine.dir/chlorine/src/chlorine.cpp.o
chlorine: CMakeFiles/chlorine.dir/build.make
chlorine: /usr/lib/x86_64-linux-gnu/libOpenCL.so
chlorine: CMakeFiles/chlorine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable chlorine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chlorine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chlorine.dir/build: chlorine

.PHONY : CMakeFiles/chlorine.dir/build

CMakeFiles/chlorine.dir/requires: CMakeFiles/chlorine.dir/chlorine/src/chlorine.cpp.o.requires

.PHONY : CMakeFiles/chlorine.dir/requires

CMakeFiles/chlorine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chlorine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chlorine.dir/clean

CMakeFiles/chlorine.dir/depend:
	cd /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a/CMakeFiles/chlorine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chlorine.dir/depend
