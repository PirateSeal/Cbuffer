# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = "/Users/PirateSeal/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/211.7442.42/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/PirateSeal/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/211.7442.42/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/PirateSeal/dev/Cbuffer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/PirateSeal/dev/Cbuffer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Cbuffer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Cbuffer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Cbuffer.dir/flags.make

CMakeFiles/Cbuffer.dir/main.c.o: CMakeFiles/Cbuffer.dir/flags.make
CMakeFiles/Cbuffer.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/PirateSeal/dev/Cbuffer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Cbuffer.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Cbuffer.dir/main.c.o -c /Users/PirateSeal/dev/Cbuffer/main.c

CMakeFiles/Cbuffer.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Cbuffer.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/PirateSeal/dev/Cbuffer/main.c > CMakeFiles/Cbuffer.dir/main.c.i

CMakeFiles/Cbuffer.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Cbuffer.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/PirateSeal/dev/Cbuffer/main.c -o CMakeFiles/Cbuffer.dir/main.c.s

CMakeFiles/Cbuffer.dir/buffer.c.o: CMakeFiles/Cbuffer.dir/flags.make
CMakeFiles/Cbuffer.dir/buffer.c.o: ../buffer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/PirateSeal/dev/Cbuffer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Cbuffer.dir/buffer.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Cbuffer.dir/buffer.c.o -c /Users/PirateSeal/dev/Cbuffer/buffer.c

CMakeFiles/Cbuffer.dir/buffer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Cbuffer.dir/buffer.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/PirateSeal/dev/Cbuffer/buffer.c > CMakeFiles/Cbuffer.dir/buffer.c.i

CMakeFiles/Cbuffer.dir/buffer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Cbuffer.dir/buffer.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/PirateSeal/dev/Cbuffer/buffer.c -o CMakeFiles/Cbuffer.dir/buffer.c.s

CMakeFiles/Cbuffer.dir/utils.c.o: CMakeFiles/Cbuffer.dir/flags.make
CMakeFiles/Cbuffer.dir/utils.c.o: ../utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/PirateSeal/dev/Cbuffer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Cbuffer.dir/utils.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Cbuffer.dir/utils.c.o -c /Users/PirateSeal/dev/Cbuffer/utils.c

CMakeFiles/Cbuffer.dir/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Cbuffer.dir/utils.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/PirateSeal/dev/Cbuffer/utils.c > CMakeFiles/Cbuffer.dir/utils.c.i

CMakeFiles/Cbuffer.dir/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Cbuffer.dir/utils.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/PirateSeal/dev/Cbuffer/utils.c -o CMakeFiles/Cbuffer.dir/utils.c.s

CMakeFiles/Cbuffer.dir/lexer.c.o: CMakeFiles/Cbuffer.dir/flags.make
CMakeFiles/Cbuffer.dir/lexer.c.o: ../lexer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/PirateSeal/dev/Cbuffer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Cbuffer.dir/lexer.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Cbuffer.dir/lexer.c.o -c /Users/PirateSeal/dev/Cbuffer/lexer.c

CMakeFiles/Cbuffer.dir/lexer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Cbuffer.dir/lexer.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/PirateSeal/dev/Cbuffer/lexer.c > CMakeFiles/Cbuffer.dir/lexer.c.i

CMakeFiles/Cbuffer.dir/lexer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Cbuffer.dir/lexer.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/PirateSeal/dev/Cbuffer/lexer.c -o CMakeFiles/Cbuffer.dir/lexer.c.s

# Object files for target Cbuffer
Cbuffer_OBJECTS = \
"CMakeFiles/Cbuffer.dir/main.c.o" \
"CMakeFiles/Cbuffer.dir/buffer.c.o" \
"CMakeFiles/Cbuffer.dir/utils.c.o" \
"CMakeFiles/Cbuffer.dir/lexer.c.o"

# External object files for target Cbuffer
Cbuffer_EXTERNAL_OBJECTS =

Cbuffer: CMakeFiles/Cbuffer.dir/main.c.o
Cbuffer: CMakeFiles/Cbuffer.dir/buffer.c.o
Cbuffer: CMakeFiles/Cbuffer.dir/utils.c.o
Cbuffer: CMakeFiles/Cbuffer.dir/lexer.c.o
Cbuffer: CMakeFiles/Cbuffer.dir/build.make
Cbuffer: CMakeFiles/Cbuffer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/PirateSeal/dev/Cbuffer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable Cbuffer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Cbuffer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Cbuffer.dir/build: Cbuffer

.PHONY : CMakeFiles/Cbuffer.dir/build

CMakeFiles/Cbuffer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Cbuffer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Cbuffer.dir/clean

CMakeFiles/Cbuffer.dir/depend:
	cd /Users/PirateSeal/dev/Cbuffer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/PirateSeal/dev/Cbuffer /Users/PirateSeal/dev/Cbuffer /Users/PirateSeal/dev/Cbuffer/cmake-build-debug /Users/PirateSeal/dev/Cbuffer/cmake-build-debug /Users/PirateSeal/dev/Cbuffer/cmake-build-debug/CMakeFiles/Cbuffer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Cbuffer.dir/depend

