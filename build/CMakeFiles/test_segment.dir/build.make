# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/liyin/anaconda/bin/cmake

# The command to remove a file.
RM = /home/liyin/anaconda/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/liyin/edison_source/segm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liyin/edison_source/segm/build

# Include any dependencies generated for this target.
include CMakeFiles/test_segment.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_segment.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_segment.dir/flags.make

CMakeFiles/test_segment.dir/test_segment.cpp.o: CMakeFiles/test_segment.dir/flags.make
CMakeFiles/test_segment.dir/test_segment.cpp.o: ../test_segment.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liyin/edison_source/segm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_segment.dir/test_segment.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_segment.dir/test_segment.cpp.o -c /home/liyin/edison_source/segm/test_segment.cpp

CMakeFiles/test_segment.dir/test_segment.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_segment.dir/test_segment.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liyin/edison_source/segm/test_segment.cpp > CMakeFiles/test_segment.dir/test_segment.cpp.i

CMakeFiles/test_segment.dir/test_segment.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_segment.dir/test_segment.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liyin/edison_source/segm/test_segment.cpp -o CMakeFiles/test_segment.dir/test_segment.cpp.s

CMakeFiles/test_segment.dir/test_segment.cpp.o.requires:

.PHONY : CMakeFiles/test_segment.dir/test_segment.cpp.o.requires

CMakeFiles/test_segment.dir/test_segment.cpp.o.provides: CMakeFiles/test_segment.dir/test_segment.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_segment.dir/build.make CMakeFiles/test_segment.dir/test_segment.cpp.o.provides.build
.PHONY : CMakeFiles/test_segment.dir/test_segment.cpp.o.provides

CMakeFiles/test_segment.dir/test_segment.cpp.o.provides.build: CMakeFiles/test_segment.dir/test_segment.cpp.o


# Object files for target test_segment
test_segment_OBJECTS = \
"CMakeFiles/test_segment.dir/test_segment.cpp.o"

# External object files for target test_segment
test_segment_EXTERNAL_OBJECTS =

test_segment: CMakeFiles/test_segment.dir/test_segment.cpp.o
test_segment: CMakeFiles/test_segment.dir/build.make
test_segment: libprocessor.a
test_segment: libdependencies.a
test_segment: CMakeFiles/test_segment.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liyin/edison_source/segm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_segment"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_segment.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_segment.dir/build: test_segment

.PHONY : CMakeFiles/test_segment.dir/build

CMakeFiles/test_segment.dir/requires: CMakeFiles/test_segment.dir/test_segment.cpp.o.requires

.PHONY : CMakeFiles/test_segment.dir/requires

CMakeFiles/test_segment.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_segment.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_segment.dir/clean

CMakeFiles/test_segment.dir/depend:
	cd /home/liyin/edison_source/segm/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liyin/edison_source/segm /home/liyin/edison_source/segm /home/liyin/edison_source/segm/build /home/liyin/edison_source/segm/build /home/liyin/edison_source/segm/build/CMakeFiles/test_segment.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_segment.dir/depend

