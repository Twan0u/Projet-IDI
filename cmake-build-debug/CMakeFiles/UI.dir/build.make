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
CMAKE_SOURCE_DIR = "/mnt/c/Users/Antoine Lambert/Documents/Projet-IDI"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/Antoine Lambert/Documents/Projet-IDI/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/UI.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/UI.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UI.dir/flags.make

CMakeFiles/UI.dir/UI.c.o: CMakeFiles/UI.dir/flags.make
CMakeFiles/UI.dir/UI.c.o: ../UI.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Antoine Lambert/Documents/Projet-IDI/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/UI.dir/UI.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/UI.dir/UI.c.o   -c "/mnt/c/Users/Antoine Lambert/Documents/Projet-IDI/UI.c"

CMakeFiles/UI.dir/UI.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/UI.dir/UI.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Antoine Lambert/Documents/Projet-IDI/UI.c" > CMakeFiles/UI.dir/UI.c.i

CMakeFiles/UI.dir/UI.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/UI.dir/UI.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Antoine Lambert/Documents/Projet-IDI/UI.c" -o CMakeFiles/UI.dir/UI.c.s

CMakeFiles/UI.dir/UI.c.o.requires:

.PHONY : CMakeFiles/UI.dir/UI.c.o.requires

CMakeFiles/UI.dir/UI.c.o.provides: CMakeFiles/UI.dir/UI.c.o.requires
	$(MAKE) -f CMakeFiles/UI.dir/build.make CMakeFiles/UI.dir/UI.c.o.provides.build
.PHONY : CMakeFiles/UI.dir/UI.c.o.provides

CMakeFiles/UI.dir/UI.c.o.provides.build: CMakeFiles/UI.dir/UI.c.o


CMakeFiles/UI.dir/classificationStatistics.c.o: CMakeFiles/UI.dir/flags.make
CMakeFiles/UI.dir/classificationStatistics.c.o: ../classificationStatistics.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Antoine Lambert/Documents/Projet-IDI/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/UI.dir/classificationStatistics.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/UI.dir/classificationStatistics.c.o   -c "/mnt/c/Users/Antoine Lambert/Documents/Projet-IDI/classificationStatistics.c"

CMakeFiles/UI.dir/classificationStatistics.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/UI.dir/classificationStatistics.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Antoine Lambert/Documents/Projet-IDI/classificationStatistics.c" > CMakeFiles/UI.dir/classificationStatistics.c.i

CMakeFiles/UI.dir/classificationStatistics.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/UI.dir/classificationStatistics.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Antoine Lambert/Documents/Projet-IDI/classificationStatistics.c" -o CMakeFiles/UI.dir/classificationStatistics.c.s

CMakeFiles/UI.dir/classificationStatistics.c.o.requires:

.PHONY : CMakeFiles/UI.dir/classificationStatistics.c.o.requires

CMakeFiles/UI.dir/classificationStatistics.c.o.provides: CMakeFiles/UI.dir/classificationStatistics.c.o.requires
	$(MAKE) -f CMakeFiles/UI.dir/build.make CMakeFiles/UI.dir/classificationStatistics.c.o.provides.build
.PHONY : CMakeFiles/UI.dir/classificationStatistics.c.o.provides

CMakeFiles/UI.dir/classificationStatistics.c.o.provides.build: CMakeFiles/UI.dir/classificationStatistics.c.o


CMakeFiles/UI.dir/interfacelib.c.o: CMakeFiles/UI.dir/flags.make
CMakeFiles/UI.dir/interfacelib.c.o: ../interfacelib.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Antoine Lambert/Documents/Projet-IDI/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/UI.dir/interfacelib.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/UI.dir/interfacelib.c.o   -c "/mnt/c/Users/Antoine Lambert/Documents/Projet-IDI/interfacelib.c"

CMakeFiles/UI.dir/interfacelib.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/UI.dir/interfacelib.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Antoine Lambert/Documents/Projet-IDI/interfacelib.c" > CMakeFiles/UI.dir/interfacelib.c.i

CMakeFiles/UI.dir/interfacelib.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/UI.dir/interfacelib.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Antoine Lambert/Documents/Projet-IDI/interfacelib.c" -o CMakeFiles/UI.dir/interfacelib.c.s

CMakeFiles/UI.dir/interfacelib.c.o.requires:

.PHONY : CMakeFiles/UI.dir/interfacelib.c.o.requires

CMakeFiles/UI.dir/interfacelib.c.o.provides: CMakeFiles/UI.dir/interfacelib.c.o.requires
	$(MAKE) -f CMakeFiles/UI.dir/build.make CMakeFiles/UI.dir/interfacelib.c.o.provides.build
.PHONY : CMakeFiles/UI.dir/interfacelib.c.o.provides

CMakeFiles/UI.dir/interfacelib.c.o.provides.build: CMakeFiles/UI.dir/interfacelib.c.o


CMakeFiles/UI.dir/dao.c.o: CMakeFiles/UI.dir/flags.make
CMakeFiles/UI.dir/dao.c.o: ../dao.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Antoine Lambert/Documents/Projet-IDI/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/UI.dir/dao.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/UI.dir/dao.c.o   -c "/mnt/c/Users/Antoine Lambert/Documents/Projet-IDI/dao.c"

CMakeFiles/UI.dir/dao.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/UI.dir/dao.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Antoine Lambert/Documents/Projet-IDI/dao.c" > CMakeFiles/UI.dir/dao.c.i

CMakeFiles/UI.dir/dao.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/UI.dir/dao.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Antoine Lambert/Documents/Projet-IDI/dao.c" -o CMakeFiles/UI.dir/dao.c.s

CMakeFiles/UI.dir/dao.c.o.requires:

.PHONY : CMakeFiles/UI.dir/dao.c.o.requires

CMakeFiles/UI.dir/dao.c.o.provides: CMakeFiles/UI.dir/dao.c.o.requires
	$(MAKE) -f CMakeFiles/UI.dir/build.make CMakeFiles/UI.dir/dao.c.o.provides.build
.PHONY : CMakeFiles/UI.dir/dao.c.o.provides

CMakeFiles/UI.dir/dao.c.o.provides.build: CMakeFiles/UI.dir/dao.c.o


# Object files for target UI
UI_OBJECTS = \
"CMakeFiles/UI.dir/UI.c.o" \
"CMakeFiles/UI.dir/classificationStatistics.c.o" \
"CMakeFiles/UI.dir/interfacelib.c.o" \
"CMakeFiles/UI.dir/dao.c.o"

# External object files for target UI
UI_EXTERNAL_OBJECTS =

UI: CMakeFiles/UI.dir/UI.c.o
UI: CMakeFiles/UI.dir/classificationStatistics.c.o
UI: CMakeFiles/UI.dir/interfacelib.c.o
UI: CMakeFiles/UI.dir/dao.c.o
UI: CMakeFiles/UI.dir/build.make
UI: CMakeFiles/UI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/Antoine Lambert/Documents/Projet-IDI/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable UI"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UI.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/UI.dir/build: UI

.PHONY : CMakeFiles/UI.dir/build

CMakeFiles/UI.dir/requires: CMakeFiles/UI.dir/UI.c.o.requires
CMakeFiles/UI.dir/requires: CMakeFiles/UI.dir/classificationStatistics.c.o.requires
CMakeFiles/UI.dir/requires: CMakeFiles/UI.dir/interfacelib.c.o.requires
CMakeFiles/UI.dir/requires: CMakeFiles/UI.dir/dao.c.o.requires

.PHONY : CMakeFiles/UI.dir/requires

CMakeFiles/UI.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/UI.dir/cmake_clean.cmake
.PHONY : CMakeFiles/UI.dir/clean

CMakeFiles/UI.dir/depend:
	cd "/mnt/c/Users/Antoine Lambert/Documents/Projet-IDI/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/Antoine Lambert/Documents/Projet-IDI" "/mnt/c/Users/Antoine Lambert/Documents/Projet-IDI" "/mnt/c/Users/Antoine Lambert/Documents/Projet-IDI/cmake-build-debug" "/mnt/c/Users/Antoine Lambert/Documents/Projet-IDI/cmake-build-debug" "/mnt/c/Users/Antoine Lambert/Documents/Projet-IDI/cmake-build-debug/CMakeFiles/UI.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/UI.dir/depend

