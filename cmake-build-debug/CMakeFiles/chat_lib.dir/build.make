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
CMAKE_COMMAND = /snap/clion/189/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/189/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/chat_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/chat_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/chat_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chat_lib.dir/flags.make

CMakeFiles/chat_lib.dir/Chat.cpp.o: CMakeFiles/chat_lib.dir/flags.make
CMakeFiles/chat_lib.dir/Chat.cpp.o: ../Chat.cpp
CMakeFiles/chat_lib.dir/Chat.cpp.o: CMakeFiles/chat_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chat_lib.dir/Chat.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chat_lib.dir/Chat.cpp.o -MF CMakeFiles/chat_lib.dir/Chat.cpp.o.d -o CMakeFiles/chat_lib.dir/Chat.cpp.o -c /home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project/Chat.cpp

CMakeFiles/chat_lib.dir/Chat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chat_lib.dir/Chat.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project/Chat.cpp > CMakeFiles/chat_lib.dir/Chat.cpp.i

CMakeFiles/chat_lib.dir/Chat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chat_lib.dir/Chat.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project/Chat.cpp -o CMakeFiles/chat_lib.dir/Chat.cpp.s

# Object files for target chat_lib
chat_lib_OBJECTS = \
"CMakeFiles/chat_lib.dir/Chat.cpp.o"

# External object files for target chat_lib
chat_lib_EXTERNAL_OBJECTS =

libchat_lib.so: CMakeFiles/chat_lib.dir/Chat.cpp.o
libchat_lib.so: CMakeFiles/chat_lib.dir/build.make
libchat_lib.so: CMakeFiles/chat_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libchat_lib.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chat_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chat_lib.dir/build: libchat_lib.so
.PHONY : CMakeFiles/chat_lib.dir/build

CMakeFiles/chat_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chat_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chat_lib.dir/clean

CMakeFiles/chat_lib.dir/depend:
	cd /home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project /home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project /home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project/cmake-build-debug /home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project/cmake-build-debug /home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project/cmake-build-debug/CMakeFiles/chat_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chat_lib.dir/depend

