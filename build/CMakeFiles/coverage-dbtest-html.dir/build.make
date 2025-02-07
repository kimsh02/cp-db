# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kimsh/Downloads/c-cpp/projects/db

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kimsh/Downloads/c-cpp/projects/db/build

# Utility rule file for coverage-dbtest-html.

# Include any custom commands dependencies for this target.
include CMakeFiles/coverage-dbtest-html.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/coverage-dbtest-html.dir/progress.make

CMakeFiles/coverage-dbtest-html:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/kimsh/Downloads/c-cpp/projects/db/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating HTML coverage report for dbtest..."
	llvm-cov show ./tests/dbtest -instr-profile=/Users/kimsh/Downloads/c-cpp/projects/db/build/coverage.profdata -format=html -output-dir=/Users/kimsh/Downloads/c-cpp/projects/db/build/coverage_html_test "-ignore-filename-regex=.*/tests/.*"

CMakeFiles/coverage-dbtest-html.dir/codegen:
.PHONY : CMakeFiles/coverage-dbtest-html.dir/codegen

coverage-dbtest-html: CMakeFiles/coverage-dbtest-html
coverage-dbtest-html: CMakeFiles/coverage-dbtest-html.dir/build.make
.PHONY : coverage-dbtest-html

# Rule to build all files generated by this target.
CMakeFiles/coverage-dbtest-html.dir/build: coverage-dbtest-html
.PHONY : CMakeFiles/coverage-dbtest-html.dir/build

CMakeFiles/coverage-dbtest-html.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/coverage-dbtest-html.dir/cmake_clean.cmake
.PHONY : CMakeFiles/coverage-dbtest-html.dir/clean

CMakeFiles/coverage-dbtest-html.dir/depend:
	cd /Users/kimsh/Downloads/c-cpp/projects/db/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kimsh/Downloads/c-cpp/projects/db /Users/kimsh/Downloads/c-cpp/projects/db /Users/kimsh/Downloads/c-cpp/projects/db/build /Users/kimsh/Downloads/c-cpp/projects/db/build /Users/kimsh/Downloads/c-cpp/projects/db/build/CMakeFiles/coverage-dbtest-html.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/coverage-dbtest-html.dir/depend

