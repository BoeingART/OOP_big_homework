# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.23.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.23.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/boeingart/OOP_big_homework

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/boeingart/OOP_big_homework

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/opt/homebrew/Cellar/cmake/3.23.1/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/opt/homebrew/Cellar/cmake/3.23.1/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/boeingart/OOP_big_homework/CMakeFiles /Users/boeingart/OOP_big_homework//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/boeingart/OOP_big_homework/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named OOP_big_homework

# Build rule for target.
OOP_big_homework: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 OOP_big_homework
.PHONY : OOP_big_homework

# fast build rule for target.
OOP_big_homework/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OOP_big_homework.dir/build.make CMakeFiles/OOP_big_homework.dir/build
.PHONY : OOP_big_homework/fast

#=============================================================================
# Target rules for targets named OOP_big_homework_autogen

# Build rule for target.
OOP_big_homework_autogen: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 OOP_big_homework_autogen
.PHONY : OOP_big_homework_autogen

# fast build rule for target.
OOP_big_homework_autogen/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OOP_big_homework_autogen.dir/build.make CMakeFiles/OOP_big_homework_autogen.dir/build
.PHONY : OOP_big_homework_autogen/fast

OOP_big_homework_autogen/mocs_compilation.o: OOP_big_homework_autogen/mocs_compilation.cpp.o
.PHONY : OOP_big_homework_autogen/mocs_compilation.o

# target to build an object file
OOP_big_homework_autogen/mocs_compilation.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OOP_big_homework.dir/build.make CMakeFiles/OOP_big_homework.dir/OOP_big_homework_autogen/mocs_compilation.cpp.o
.PHONY : OOP_big_homework_autogen/mocs_compilation.cpp.o

OOP_big_homework_autogen/mocs_compilation.i: OOP_big_homework_autogen/mocs_compilation.cpp.i
.PHONY : OOP_big_homework_autogen/mocs_compilation.i

# target to preprocess a source file
OOP_big_homework_autogen/mocs_compilation.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OOP_big_homework.dir/build.make CMakeFiles/OOP_big_homework.dir/OOP_big_homework_autogen/mocs_compilation.cpp.i
.PHONY : OOP_big_homework_autogen/mocs_compilation.cpp.i

OOP_big_homework_autogen/mocs_compilation.s: OOP_big_homework_autogen/mocs_compilation.cpp.s
.PHONY : OOP_big_homework_autogen/mocs_compilation.s

# target to generate assembly for a file
OOP_big_homework_autogen/mocs_compilation.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OOP_big_homework.dir/build.make CMakeFiles/OOP_big_homework.dir/OOP_big_homework_autogen/mocs_compilation.cpp.s
.PHONY : OOP_big_homework_autogen/mocs_compilation.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OOP_big_homework.dir/build.make CMakeFiles/OOP_big_homework.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OOP_big_homework.dir/build.make CMakeFiles/OOP_big_homework.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OOP_big_homework.dir/build.make CMakeFiles/OOP_big_homework.dir/main.cpp.s
.PHONY : main.cpp.s

mainwindow.o: mainwindow.cpp.o
.PHONY : mainwindow.o

# target to build an object file
mainwindow.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OOP_big_homework.dir/build.make CMakeFiles/OOP_big_homework.dir/mainwindow.cpp.o
.PHONY : mainwindow.cpp.o

mainwindow.i: mainwindow.cpp.i
.PHONY : mainwindow.i

# target to preprocess a source file
mainwindow.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OOP_big_homework.dir/build.make CMakeFiles/OOP_big_homework.dir/mainwindow.cpp.i
.PHONY : mainwindow.cpp.i

mainwindow.s: mainwindow.cpp.s
.PHONY : mainwindow.s

# target to generate assembly for a file
mainwindow.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OOP_big_homework.dir/build.make CMakeFiles/OOP_big_homework.dir/mainwindow.cpp.s
.PHONY : mainwindow.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... OOP_big_homework_autogen"
	@echo "... OOP_big_homework"
	@echo "... OOP_big_homework_autogen/mocs_compilation.o"
	@echo "... OOP_big_homework_autogen/mocs_compilation.i"
	@echo "... OOP_big_homework_autogen/mocs_compilation.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... mainwindow.o"
	@echo "... mainwindow.i"
	@echo "... mainwindow.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

