# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/julius/projects/c/open_gl_start

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/julius/projects/c/open_gl_start/build

# Include any dependencies generated for this target.
include CMakeFiles/open_gl_start.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/open_gl_start.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/open_gl_start.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/open_gl_start.dir/flags.make

CMakeFiles/open_gl_start.dir/src/shader/shader.c.o: CMakeFiles/open_gl_start.dir/flags.make
CMakeFiles/open_gl_start.dir/src/shader/shader.c.o: /home/julius/projects/c/open_gl_start/src/shader/shader.c
CMakeFiles/open_gl_start.dir/src/shader/shader.c.o: CMakeFiles/open_gl_start.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/julius/projects/c/open_gl_start/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/open_gl_start.dir/src/shader/shader.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/open_gl_start.dir/src/shader/shader.c.o -MF CMakeFiles/open_gl_start.dir/src/shader/shader.c.o.d -o CMakeFiles/open_gl_start.dir/src/shader/shader.c.o -c /home/julius/projects/c/open_gl_start/src/shader/shader.c

CMakeFiles/open_gl_start.dir/src/shader/shader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/open_gl_start.dir/src/shader/shader.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/julius/projects/c/open_gl_start/src/shader/shader.c > CMakeFiles/open_gl_start.dir/src/shader/shader.c.i

CMakeFiles/open_gl_start.dir/src/shader/shader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/open_gl_start.dir/src/shader/shader.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/julius/projects/c/open_gl_start/src/shader/shader.c -o CMakeFiles/open_gl_start.dir/src/shader/shader.c.s

CMakeFiles/open_gl_start.dir/src/main.c.o: CMakeFiles/open_gl_start.dir/flags.make
CMakeFiles/open_gl_start.dir/src/main.c.o: /home/julius/projects/c/open_gl_start/src/main.c
CMakeFiles/open_gl_start.dir/src/main.c.o: CMakeFiles/open_gl_start.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/julius/projects/c/open_gl_start/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/open_gl_start.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/open_gl_start.dir/src/main.c.o -MF CMakeFiles/open_gl_start.dir/src/main.c.o.d -o CMakeFiles/open_gl_start.dir/src/main.c.o -c /home/julius/projects/c/open_gl_start/src/main.c

CMakeFiles/open_gl_start.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/open_gl_start.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/julius/projects/c/open_gl_start/src/main.c > CMakeFiles/open_gl_start.dir/src/main.c.i

CMakeFiles/open_gl_start.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/open_gl_start.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/julius/projects/c/open_gl_start/src/main.c -o CMakeFiles/open_gl_start.dir/src/main.c.s

CMakeFiles/open_gl_start.dir/src/glad.c.o: CMakeFiles/open_gl_start.dir/flags.make
CMakeFiles/open_gl_start.dir/src/glad.c.o: /home/julius/projects/c/open_gl_start/src/glad.c
CMakeFiles/open_gl_start.dir/src/glad.c.o: CMakeFiles/open_gl_start.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/julius/projects/c/open_gl_start/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/open_gl_start.dir/src/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/open_gl_start.dir/src/glad.c.o -MF CMakeFiles/open_gl_start.dir/src/glad.c.o.d -o CMakeFiles/open_gl_start.dir/src/glad.c.o -c /home/julius/projects/c/open_gl_start/src/glad.c

CMakeFiles/open_gl_start.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/open_gl_start.dir/src/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/julius/projects/c/open_gl_start/src/glad.c > CMakeFiles/open_gl_start.dir/src/glad.c.i

CMakeFiles/open_gl_start.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/open_gl_start.dir/src/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/julius/projects/c/open_gl_start/src/glad.c -o CMakeFiles/open_gl_start.dir/src/glad.c.s

CMakeFiles/open_gl_start.dir/src/buffer.c.o: CMakeFiles/open_gl_start.dir/flags.make
CMakeFiles/open_gl_start.dir/src/buffer.c.o: /home/julius/projects/c/open_gl_start/src/buffer.c
CMakeFiles/open_gl_start.dir/src/buffer.c.o: CMakeFiles/open_gl_start.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/julius/projects/c/open_gl_start/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/open_gl_start.dir/src/buffer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/open_gl_start.dir/src/buffer.c.o -MF CMakeFiles/open_gl_start.dir/src/buffer.c.o.d -o CMakeFiles/open_gl_start.dir/src/buffer.c.o -c /home/julius/projects/c/open_gl_start/src/buffer.c

CMakeFiles/open_gl_start.dir/src/buffer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/open_gl_start.dir/src/buffer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/julius/projects/c/open_gl_start/src/buffer.c > CMakeFiles/open_gl_start.dir/src/buffer.c.i

CMakeFiles/open_gl_start.dir/src/buffer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/open_gl_start.dir/src/buffer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/julius/projects/c/open_gl_start/src/buffer.c -o CMakeFiles/open_gl_start.dir/src/buffer.c.s

CMakeFiles/open_gl_start.dir/src/model_loader.c.o: CMakeFiles/open_gl_start.dir/flags.make
CMakeFiles/open_gl_start.dir/src/model_loader.c.o: /home/julius/projects/c/open_gl_start/src/model_loader.c
CMakeFiles/open_gl_start.dir/src/model_loader.c.o: CMakeFiles/open_gl_start.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/julius/projects/c/open_gl_start/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/open_gl_start.dir/src/model_loader.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/open_gl_start.dir/src/model_loader.c.o -MF CMakeFiles/open_gl_start.dir/src/model_loader.c.o.d -o CMakeFiles/open_gl_start.dir/src/model_loader.c.o -c /home/julius/projects/c/open_gl_start/src/model_loader.c

CMakeFiles/open_gl_start.dir/src/model_loader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/open_gl_start.dir/src/model_loader.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/julius/projects/c/open_gl_start/src/model_loader.c > CMakeFiles/open_gl_start.dir/src/model_loader.c.i

CMakeFiles/open_gl_start.dir/src/model_loader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/open_gl_start.dir/src/model_loader.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/julius/projects/c/open_gl_start/src/model_loader.c -o CMakeFiles/open_gl_start.dir/src/model_loader.c.s

CMakeFiles/open_gl_start.dir/src/utils.c.o: CMakeFiles/open_gl_start.dir/flags.make
CMakeFiles/open_gl_start.dir/src/utils.c.o: /home/julius/projects/c/open_gl_start/src/utils.c
CMakeFiles/open_gl_start.dir/src/utils.c.o: CMakeFiles/open_gl_start.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/julius/projects/c/open_gl_start/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/open_gl_start.dir/src/utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/open_gl_start.dir/src/utils.c.o -MF CMakeFiles/open_gl_start.dir/src/utils.c.o.d -o CMakeFiles/open_gl_start.dir/src/utils.c.o -c /home/julius/projects/c/open_gl_start/src/utils.c

CMakeFiles/open_gl_start.dir/src/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/open_gl_start.dir/src/utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/julius/projects/c/open_gl_start/src/utils.c > CMakeFiles/open_gl_start.dir/src/utils.c.i

CMakeFiles/open_gl_start.dir/src/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/open_gl_start.dir/src/utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/julius/projects/c/open_gl_start/src/utils.c -o CMakeFiles/open_gl_start.dir/src/utils.c.s

# Object files for target open_gl_start
open_gl_start_OBJECTS = \
"CMakeFiles/open_gl_start.dir/src/shader/shader.c.o" \
"CMakeFiles/open_gl_start.dir/src/main.c.o" \
"CMakeFiles/open_gl_start.dir/src/glad.c.o" \
"CMakeFiles/open_gl_start.dir/src/buffer.c.o" \
"CMakeFiles/open_gl_start.dir/src/model_loader.c.o" \
"CMakeFiles/open_gl_start.dir/src/utils.c.o"

# External object files for target open_gl_start
open_gl_start_EXTERNAL_OBJECTS =

open_gl_start: CMakeFiles/open_gl_start.dir/src/shader/shader.c.o
open_gl_start: CMakeFiles/open_gl_start.dir/src/main.c.o
open_gl_start: CMakeFiles/open_gl_start.dir/src/glad.c.o
open_gl_start: CMakeFiles/open_gl_start.dir/src/buffer.c.o
open_gl_start: CMakeFiles/open_gl_start.dir/src/model_loader.c.o
open_gl_start: CMakeFiles/open_gl_start.dir/src/utils.c.o
open_gl_start: CMakeFiles/open_gl_start.dir/build.make
open_gl_start: /usr/lib/x86_64-linux-gnu/libGLX.so
open_gl_start: /usr/lib/x86_64-linux-gnu/libOpenGL.so
open_gl_start: CMakeFiles/open_gl_start.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/julius/projects/c/open_gl_start/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable open_gl_start"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/open_gl_start.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/open_gl_start.dir/build: open_gl_start
.PHONY : CMakeFiles/open_gl_start.dir/build

CMakeFiles/open_gl_start.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/open_gl_start.dir/cmake_clean.cmake
.PHONY : CMakeFiles/open_gl_start.dir/clean

CMakeFiles/open_gl_start.dir/depend:
	cd /home/julius/projects/c/open_gl_start/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/julius/projects/c/open_gl_start /home/julius/projects/c/open_gl_start /home/julius/projects/c/open_gl_start/build /home/julius/projects/c/open_gl_start/build /home/julius/projects/c/open_gl_start/build/CMakeFiles/open_gl_start.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/open_gl_start.dir/depend

