# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\github\cpp\Skillbox\module_22_Reading_from_files\22_2_Text_file_viewer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\github\cpp\Skillbox\module_22_Reading_from_files\22_2_Text_file_viewer\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/22_2_Text_file_viewer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/22_2_Text_file_viewer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/22_2_Text_file_viewer.dir/flags.make

CMakeFiles/22_2_Text_file_viewer.dir/main.cpp.obj: CMakeFiles/22_2_Text_file_viewer.dir/flags.make
CMakeFiles/22_2_Text_file_viewer.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\github\cpp\Skillbox\module_22_Reading_from_files\22_2_Text_file_viewer\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/22_2_Text_file_viewer.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\22_2_Text_file_viewer.dir\main.cpp.obj -c D:\github\cpp\Skillbox\module_22_Reading_from_files\22_2_Text_file_viewer\main.cpp

CMakeFiles/22_2_Text_file_viewer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/22_2_Text_file_viewer.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\github\cpp\Skillbox\module_22_Reading_from_files\22_2_Text_file_viewer\main.cpp > CMakeFiles\22_2_Text_file_viewer.dir\main.cpp.i

CMakeFiles/22_2_Text_file_viewer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/22_2_Text_file_viewer.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\github\cpp\Skillbox\module_22_Reading_from_files\22_2_Text_file_viewer\main.cpp -o CMakeFiles\22_2_Text_file_viewer.dir\main.cpp.s

# Object files for target 22_2_Text_file_viewer
22_2_Text_file_viewer_OBJECTS = \
"CMakeFiles/22_2_Text_file_viewer.dir/main.cpp.obj"

# External object files for target 22_2_Text_file_viewer
22_2_Text_file_viewer_EXTERNAL_OBJECTS =

22_2_Text_file_viewer.exe: CMakeFiles/22_2_Text_file_viewer.dir/main.cpp.obj
22_2_Text_file_viewer.exe: CMakeFiles/22_2_Text_file_viewer.dir/build.make
22_2_Text_file_viewer.exe: CMakeFiles/22_2_Text_file_viewer.dir/linklibs.rsp
22_2_Text_file_viewer.exe: CMakeFiles/22_2_Text_file_viewer.dir/objects1.rsp
22_2_Text_file_viewer.exe: CMakeFiles/22_2_Text_file_viewer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\github\cpp\Skillbox\module_22_Reading_from_files\22_2_Text_file_viewer\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 22_2_Text_file_viewer.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\22_2_Text_file_viewer.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/22_2_Text_file_viewer.dir/build: 22_2_Text_file_viewer.exe

.PHONY : CMakeFiles/22_2_Text_file_viewer.dir/build

CMakeFiles/22_2_Text_file_viewer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\22_2_Text_file_viewer.dir\cmake_clean.cmake
.PHONY : CMakeFiles/22_2_Text_file_viewer.dir/clean

CMakeFiles/22_2_Text_file_viewer.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\github\cpp\Skillbox\module_22_Reading_from_files\22_2_Text_file_viewer D:\github\cpp\Skillbox\module_22_Reading_from_files\22_2_Text_file_viewer D:\github\cpp\Skillbox\module_22_Reading_from_files\22_2_Text_file_viewer\cmake-build-debug D:\github\cpp\Skillbox\module_22_Reading_from_files\22_2_Text_file_viewer\cmake-build-debug D:\github\cpp\Skillbox\module_22_Reading_from_files\22_2_Text_file_viewer\cmake-build-debug\CMakeFiles\22_2_Text_file_viewer.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/22_2_Text_file_viewer.dir/depend

