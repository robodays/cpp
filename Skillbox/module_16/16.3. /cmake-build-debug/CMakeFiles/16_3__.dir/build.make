# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/vladimir/Загрузки/clion-2020.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/vladimir/Загрузки/clion-2020.2.5/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/vladimir/cppgit/Skillbox/module_16/16.3. "

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/vladimir/cppgit/Skillbox/module_16/16.3. /cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/16_3__.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/16_3__.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/16_3__.dir/flags.make

CMakeFiles/16_3__.dir/main.cpp.o: CMakeFiles/16_3__.dir/flags.make
CMakeFiles/16_3__.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/vladimir/cppgit/Skillbox/module_16/16.3. /cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/16_3__.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/16_3__.dir/main.cpp.o -c "/home/vladimir/cppgit/Skillbox/module_16/16.3. /main.cpp"

CMakeFiles/16_3__.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/16_3__.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/vladimir/cppgit/Skillbox/module_16/16.3. /main.cpp" > CMakeFiles/16_3__.dir/main.cpp.i

CMakeFiles/16_3__.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/16_3__.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/vladimir/cppgit/Skillbox/module_16/16.3. /main.cpp" -o CMakeFiles/16_3__.dir/main.cpp.s

# Object files for target 16_3__
16_3___OBJECTS = \
"CMakeFiles/16_3__.dir/main.cpp.o"

# External object files for target 16_3__
16_3___EXTERNAL_OBJECTS =

16_3__: CMakeFiles/16_3__.dir/main.cpp.o
16_3__: CMakeFiles/16_3__.dir/build.make
16_3__: CMakeFiles/16_3__.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/vladimir/cppgit/Skillbox/module_16/16.3. /cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 16_3__"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/16_3__.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/16_3__.dir/build: 16_3__

.PHONY : CMakeFiles/16_3__.dir/build

CMakeFiles/16_3__.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/16_3__.dir/cmake_clean.cmake
.PHONY : CMakeFiles/16_3__.dir/clean

CMakeFiles/16_3__.dir/depend:
	cd "/home/vladimir/cppgit/Skillbox/module_16/16.3. /cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/vladimir/cppgit/Skillbox/module_16/16.3. " "/home/vladimir/cppgit/Skillbox/module_16/16.3. " "/home/vladimir/cppgit/Skillbox/module_16/16.3. /cmake-build-debug" "/home/vladimir/cppgit/Skillbox/module_16/16.3. /cmake-build-debug" "/home/vladimir/cppgit/Skillbox/module_16/16.3. /cmake-build-debug/CMakeFiles/16_3__.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/16_3__.dir/depend

