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
include CMakeFiles/processor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/processor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/processor.dir/flags.make

CMakeFiles/processor.dir/msImageProcessor.cpp.o: CMakeFiles/processor.dir/flags.make
CMakeFiles/processor.dir/msImageProcessor.cpp.o: ../msImageProcessor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liyin/edison_source/segm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/processor.dir/msImageProcessor.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/processor.dir/msImageProcessor.cpp.o -c /home/liyin/edison_source/segm/msImageProcessor.cpp

CMakeFiles/processor.dir/msImageProcessor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/processor.dir/msImageProcessor.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liyin/edison_source/segm/msImageProcessor.cpp > CMakeFiles/processor.dir/msImageProcessor.cpp.i

CMakeFiles/processor.dir/msImageProcessor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/processor.dir/msImageProcessor.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liyin/edison_source/segm/msImageProcessor.cpp -o CMakeFiles/processor.dir/msImageProcessor.cpp.s

CMakeFiles/processor.dir/msImageProcessor.cpp.o.requires:

.PHONY : CMakeFiles/processor.dir/msImageProcessor.cpp.o.requires

CMakeFiles/processor.dir/msImageProcessor.cpp.o.provides: CMakeFiles/processor.dir/msImageProcessor.cpp.o.requires
	$(MAKE) -f CMakeFiles/processor.dir/build.make CMakeFiles/processor.dir/msImageProcessor.cpp.o.provides.build
.PHONY : CMakeFiles/processor.dir/msImageProcessor.cpp.o.provides

CMakeFiles/processor.dir/msImageProcessor.cpp.o.provides.build: CMakeFiles/processor.dir/msImageProcessor.cpp.o


# Object files for target processor
processor_OBJECTS = \
"CMakeFiles/processor.dir/msImageProcessor.cpp.o"

# External object files for target processor
processor_EXTERNAL_OBJECTS =

libprocessor.a: CMakeFiles/processor.dir/msImageProcessor.cpp.o
libprocessor.a: CMakeFiles/processor.dir/build.make
libprocessor.a: CMakeFiles/processor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liyin/edison_source/segm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libprocessor.a"
	$(CMAKE_COMMAND) -P CMakeFiles/processor.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/processor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/processor.dir/build: libprocessor.a

.PHONY : CMakeFiles/processor.dir/build

CMakeFiles/processor.dir/requires: CMakeFiles/processor.dir/msImageProcessor.cpp.o.requires

.PHONY : CMakeFiles/processor.dir/requires

CMakeFiles/processor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/processor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/processor.dir/clean

CMakeFiles/processor.dir/depend:
	cd /home/liyin/edison_source/segm/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liyin/edison_source/segm /home/liyin/edison_source/segm /home/liyin/edison_source/segm/build /home/liyin/edison_source/segm/build /home/liyin/edison_source/segm/build/CMakeFiles/processor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/processor.dir/depend

