# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/arya/Legen-waitforit/cpp/boost

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arya/Legen-waitforit/cpp/boost

# Include any dependencies generated for this target.
include CMakeFiles/boost_thread.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/boost_thread.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/boost_thread.dir/flags.make

CMakeFiles/boost_thread.dir/boost_thread.o: CMakeFiles/boost_thread.dir/flags.make
CMakeFiles/boost_thread.dir/boost_thread.o: boost_thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arya/Legen-waitforit/cpp/boost/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/boost_thread.dir/boost_thread.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boost_thread.dir/boost_thread.o -c /home/arya/Legen-waitforit/cpp/boost/boost_thread.cpp

CMakeFiles/boost_thread.dir/boost_thread.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boost_thread.dir/boost_thread.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arya/Legen-waitforit/cpp/boost/boost_thread.cpp > CMakeFiles/boost_thread.dir/boost_thread.i

CMakeFiles/boost_thread.dir/boost_thread.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boost_thread.dir/boost_thread.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arya/Legen-waitforit/cpp/boost/boost_thread.cpp -o CMakeFiles/boost_thread.dir/boost_thread.s

# Object files for target boost_thread
boost_thread_OBJECTS = \
"CMakeFiles/boost_thread.dir/boost_thread.o"

# External object files for target boost_thread
boost_thread_EXTERNAL_OBJECTS =

boost_thread: CMakeFiles/boost_thread.dir/boost_thread.o
boost_thread: CMakeFiles/boost_thread.dir/build.make
boost_thread: CMakeFiles/boost_thread.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arya/Legen-waitforit/cpp/boost/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable boost_thread"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/boost_thread.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/boost_thread.dir/build: boost_thread

.PHONY : CMakeFiles/boost_thread.dir/build

CMakeFiles/boost_thread.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/boost_thread.dir/cmake_clean.cmake
.PHONY : CMakeFiles/boost_thread.dir/clean

CMakeFiles/boost_thread.dir/depend:
	cd /home/arya/Legen-waitforit/cpp/boost && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arya/Legen-waitforit/cpp/boost /home/arya/Legen-waitforit/cpp/boost /home/arya/Legen-waitforit/cpp/boost /home/arya/Legen-waitforit/cpp/boost /home/arya/Legen-waitforit/cpp/boost/CMakeFiles/boost_thread.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/boost_thread.dir/depend

