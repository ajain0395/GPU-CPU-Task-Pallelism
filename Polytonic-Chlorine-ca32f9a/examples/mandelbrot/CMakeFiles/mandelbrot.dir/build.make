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
include examples/mandelbrot/CMakeFiles/mandelbrot.dir/depend.make

# Include the progress variables for this target.
include examples/mandelbrot/CMakeFiles/mandelbrot.dir/progress.make

# Include the compile flags for this target's objects.
include examples/mandelbrot/CMakeFiles/mandelbrot.dir/flags.make

examples/mandelbrot/CMakeFiles/mandelbrot.dir/mandelbrot.cpp.o: examples/mandelbrot/CMakeFiles/mandelbrot.dir/flags.make
examples/mandelbrot/CMakeFiles/mandelbrot.dir/mandelbrot.cpp.o: examples/mandelbrot/mandelbrot.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/mandelbrot/CMakeFiles/mandelbrot.dir/mandelbrot.cpp.o"
	cd /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a/examples/mandelbrot && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mandelbrot.dir/mandelbrot.cpp.o -c /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a/examples/mandelbrot/mandelbrot.cpp

examples/mandelbrot/CMakeFiles/mandelbrot.dir/mandelbrot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mandelbrot.dir/mandelbrot.cpp.i"
	cd /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a/examples/mandelbrot && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a/examples/mandelbrot/mandelbrot.cpp > CMakeFiles/mandelbrot.dir/mandelbrot.cpp.i

examples/mandelbrot/CMakeFiles/mandelbrot.dir/mandelbrot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mandelbrot.dir/mandelbrot.cpp.s"
	cd /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a/examples/mandelbrot && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a/examples/mandelbrot/mandelbrot.cpp -o CMakeFiles/mandelbrot.dir/mandelbrot.cpp.s

examples/mandelbrot/CMakeFiles/mandelbrot.dir/mandelbrot.cpp.o.requires:

.PHONY : examples/mandelbrot/CMakeFiles/mandelbrot.dir/mandelbrot.cpp.o.requires

examples/mandelbrot/CMakeFiles/mandelbrot.dir/mandelbrot.cpp.o.provides: examples/mandelbrot/CMakeFiles/mandelbrot.dir/mandelbrot.cpp.o.requires
	$(MAKE) -f examples/mandelbrot/CMakeFiles/mandelbrot.dir/build.make examples/mandelbrot/CMakeFiles/mandelbrot.dir/mandelbrot.cpp.o.provides.build
.PHONY : examples/mandelbrot/CMakeFiles/mandelbrot.dir/mandelbrot.cpp.o.provides

examples/mandelbrot/CMakeFiles/mandelbrot.dir/mandelbrot.cpp.o.provides.build: examples/mandelbrot/CMakeFiles/mandelbrot.dir/mandelbrot.cpp.o


# Object files for target mandelbrot
mandelbrot_OBJECTS = \
"CMakeFiles/mandelbrot.dir/mandelbrot.cpp.o"

# External object files for target mandelbrot
mandelbrot_EXTERNAL_OBJECTS =

examples/mandelbrot/mandelbrot: examples/mandelbrot/CMakeFiles/mandelbrot.dir/mandelbrot.cpp.o
examples/mandelbrot/mandelbrot: examples/mandelbrot/CMakeFiles/mandelbrot.dir/build.make
examples/mandelbrot/mandelbrot: /usr/lib/x86_64-linux-gnu/libOpenCL.so
examples/mandelbrot/mandelbrot: examples/mandelbrot/CMakeFiles/mandelbrot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mandelbrot"
	cd /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a/examples/mandelbrot && /usr/bin/cmake -E copy /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a/examples/mandelbrot/mandelbrot.cl /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a/examples/mandelbrot/mandelbrot.cl
	cd /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a/examples/mandelbrot && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mandelbrot.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/mandelbrot/CMakeFiles/mandelbrot.dir/build: examples/mandelbrot/mandelbrot

.PHONY : examples/mandelbrot/CMakeFiles/mandelbrot.dir/build

examples/mandelbrot/CMakeFiles/mandelbrot.dir/requires: examples/mandelbrot/CMakeFiles/mandelbrot.dir/mandelbrot.cpp.o.requires

.PHONY : examples/mandelbrot/CMakeFiles/mandelbrot.dir/requires

examples/mandelbrot/CMakeFiles/mandelbrot.dir/clean:
	cd /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a/examples/mandelbrot && $(CMAKE_COMMAND) -P CMakeFiles/mandelbrot.dir/cmake_clean.cmake
.PHONY : examples/mandelbrot/CMakeFiles/mandelbrot.dir/clean

examples/mandelbrot/CMakeFiles/mandelbrot.dir/depend:
	cd /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a/examples/mandelbrot /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a/examples/mandelbrot /home/ashish/repos/fpp-project/Polytonic-Chlorine-ca32f9a/examples/mandelbrot/CMakeFiles/mandelbrot.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/mandelbrot/CMakeFiles/mandelbrot.dir/depend

