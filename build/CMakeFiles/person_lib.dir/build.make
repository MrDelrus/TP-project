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
CMAKE_SOURCE_DIR = /home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project/build

# Include any dependencies generated for this target.
include CMakeFiles/person_lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/person_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/person_lib.dir/flags.make

CMakeFiles/person_lib.dir/Person.cpp.o: CMakeFiles/person_lib.dir/flags.make
CMakeFiles/person_lib.dir/Person.cpp.o: ../Person.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/person_lib.dir/Person.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/person_lib.dir/Person.cpp.o -c /home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project/Person.cpp

CMakeFiles/person_lib.dir/Person.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/person_lib.dir/Person.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project/Person.cpp > CMakeFiles/person_lib.dir/Person.cpp.i

CMakeFiles/person_lib.dir/Person.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/person_lib.dir/Person.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project/Person.cpp -o CMakeFiles/person_lib.dir/Person.cpp.s

# Object files for target person_lib
person_lib_OBJECTS = \
"CMakeFiles/person_lib.dir/Person.cpp.o"

# External object files for target person_lib
person_lib_EXTERNAL_OBJECTS =

libperson_lib.so: CMakeFiles/person_lib.dir/Person.cpp.o
libperson_lib.so: CMakeFiles/person_lib.dir/build.make
libperson_lib.so: CMakeFiles/person_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libperson_lib.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/person_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/person_lib.dir/build: libperson_lib.so

.PHONY : CMakeFiles/person_lib.dir/build

CMakeFiles/person_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/person_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/person_lib.dir/clean

CMakeFiles/person_lib.dir/depend:
	cd /home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project /home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project /home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project/build /home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project/build /home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project/build/CMakeFiles/person_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/person_lib.dir/depend

