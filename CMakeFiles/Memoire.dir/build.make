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
CMAKE_SOURCE_DIR = /media/racimrgh/Windows-SSD/Users/racim/OneDrive/Documents/L3-CERGY/S2/OS/projets/OS-memory-simulation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/racimrgh/Windows-SSD/Users/racim/OneDrive/Documents/L3-CERGY/S2/OS/projets/OS-memory-simulation

# Include any dependencies generated for this target.
include CMakeFiles/Memoire.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Memoire.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Memoire.dir/flags.make

CMakeFiles/Memoire.dir/main.c.o: CMakeFiles/Memoire.dir/flags.make
CMakeFiles/Memoire.dir/main.c.o: main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/racimrgh/Windows-SSD/Users/racim/OneDrive/Documents/L3-CERGY/S2/OS/projets/OS-memory-simulation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Memoire.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Memoire.dir/main.c.o   -c /media/racimrgh/Windows-SSD/Users/racim/OneDrive/Documents/L3-CERGY/S2/OS/projets/OS-memory-simulation/main.c

CMakeFiles/Memoire.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Memoire.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/racimrgh/Windows-SSD/Users/racim/OneDrive/Documents/L3-CERGY/S2/OS/projets/OS-memory-simulation/main.c > CMakeFiles/Memoire.dir/main.c.i

CMakeFiles/Memoire.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Memoire.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/racimrgh/Windows-SSD/Users/racim/OneDrive/Documents/L3-CERGY/S2/OS/projets/OS-memory-simulation/main.c -o CMakeFiles/Memoire.dir/main.c.s

CMakeFiles/Memoire.dir/src/menu.c.o: CMakeFiles/Memoire.dir/flags.make
CMakeFiles/Memoire.dir/src/menu.c.o: src/menu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/racimrgh/Windows-SSD/Users/racim/OneDrive/Documents/L3-CERGY/S2/OS/projets/OS-memory-simulation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Memoire.dir/src/menu.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Memoire.dir/src/menu.c.o   -c /media/racimrgh/Windows-SSD/Users/racim/OneDrive/Documents/L3-CERGY/S2/OS/projets/OS-memory-simulation/src/menu.c

CMakeFiles/Memoire.dir/src/menu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Memoire.dir/src/menu.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/racimrgh/Windows-SSD/Users/racim/OneDrive/Documents/L3-CERGY/S2/OS/projets/OS-memory-simulation/src/menu.c > CMakeFiles/Memoire.dir/src/menu.c.i

CMakeFiles/Memoire.dir/src/menu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Memoire.dir/src/menu.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/racimrgh/Windows-SSD/Users/racim/OneDrive/Documents/L3-CERGY/S2/OS/projets/OS-memory-simulation/src/menu.c -o CMakeFiles/Memoire.dir/src/menu.c.s

CMakeFiles/Memoire.dir/src/memory.c.o: CMakeFiles/Memoire.dir/flags.make
CMakeFiles/Memoire.dir/src/memory.c.o: src/memory.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/racimrgh/Windows-SSD/Users/racim/OneDrive/Documents/L3-CERGY/S2/OS/projets/OS-memory-simulation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Memoire.dir/src/memory.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Memoire.dir/src/memory.c.o   -c /media/racimrgh/Windows-SSD/Users/racim/OneDrive/Documents/L3-CERGY/S2/OS/projets/OS-memory-simulation/src/memory.c

CMakeFiles/Memoire.dir/src/memory.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Memoire.dir/src/memory.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/racimrgh/Windows-SSD/Users/racim/OneDrive/Documents/L3-CERGY/S2/OS/projets/OS-memory-simulation/src/memory.c > CMakeFiles/Memoire.dir/src/memory.c.i

CMakeFiles/Memoire.dir/src/memory.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Memoire.dir/src/memory.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/racimrgh/Windows-SSD/Users/racim/OneDrive/Documents/L3-CERGY/S2/OS/projets/OS-memory-simulation/src/memory.c -o CMakeFiles/Memoire.dir/src/memory.c.s

CMakeFiles/Memoire.dir/src/process.c.o: CMakeFiles/Memoire.dir/flags.make
CMakeFiles/Memoire.dir/src/process.c.o: src/process.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/racimrgh/Windows-SSD/Users/racim/OneDrive/Documents/L3-CERGY/S2/OS/projets/OS-memory-simulation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Memoire.dir/src/process.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Memoire.dir/src/process.c.o   -c /media/racimrgh/Windows-SSD/Users/racim/OneDrive/Documents/L3-CERGY/S2/OS/projets/OS-memory-simulation/src/process.c

CMakeFiles/Memoire.dir/src/process.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Memoire.dir/src/process.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/racimrgh/Windows-SSD/Users/racim/OneDrive/Documents/L3-CERGY/S2/OS/projets/OS-memory-simulation/src/process.c > CMakeFiles/Memoire.dir/src/process.c.i

CMakeFiles/Memoire.dir/src/process.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Memoire.dir/src/process.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/racimrgh/Windows-SSD/Users/racim/OneDrive/Documents/L3-CERGY/S2/OS/projets/OS-memory-simulation/src/process.c -o CMakeFiles/Memoire.dir/src/process.c.s

# Object files for target Memoire
Memoire_OBJECTS = \
"CMakeFiles/Memoire.dir/main.c.o" \
"CMakeFiles/Memoire.dir/src/menu.c.o" \
"CMakeFiles/Memoire.dir/src/memory.c.o" \
"CMakeFiles/Memoire.dir/src/process.c.o"

# External object files for target Memoire
Memoire_EXTERNAL_OBJECTS =

Memoire: CMakeFiles/Memoire.dir/main.c.o
Memoire: CMakeFiles/Memoire.dir/src/menu.c.o
Memoire: CMakeFiles/Memoire.dir/src/memory.c.o
Memoire: CMakeFiles/Memoire.dir/src/process.c.o
Memoire: CMakeFiles/Memoire.dir/build.make
Memoire: /usr/lib/x86_64-linux-gnu/libcurses.so
Memoire: /usr/lib/x86_64-linux-gnu/libform.so
Memoire: CMakeFiles/Memoire.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/racimrgh/Windows-SSD/Users/racim/OneDrive/Documents/L3-CERGY/S2/OS/projets/OS-memory-simulation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable Memoire"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Memoire.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Memoire.dir/build: Memoire

.PHONY : CMakeFiles/Memoire.dir/build

CMakeFiles/Memoire.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Memoire.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Memoire.dir/clean

CMakeFiles/Memoire.dir/depend:
	cd /media/racimrgh/Windows-SSD/Users/racim/OneDrive/Documents/L3-CERGY/S2/OS/projets/OS-memory-simulation && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/racimrgh/Windows-SSD/Users/racim/OneDrive/Documents/L3-CERGY/S2/OS/projets/OS-memory-simulation /media/racimrgh/Windows-SSD/Users/racim/OneDrive/Documents/L3-CERGY/S2/OS/projets/OS-memory-simulation /media/racimrgh/Windows-SSD/Users/racim/OneDrive/Documents/L3-CERGY/S2/OS/projets/OS-memory-simulation /media/racimrgh/Windows-SSD/Users/racim/OneDrive/Documents/L3-CERGY/S2/OS/projets/OS-memory-simulation /media/racimrgh/Windows-SSD/Users/racim/OneDrive/Documents/L3-CERGY/S2/OS/projets/OS-memory-simulation/CMakeFiles/Memoire.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Memoire.dir/depend

