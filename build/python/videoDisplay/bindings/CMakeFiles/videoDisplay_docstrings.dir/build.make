# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /home/rohit/radioconda/bin/cmake

# The command to remove a file.
RM = /home/rohit/radioconda/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rohit/Videos/video/gr/gr-videoDisplay

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rohit/Videos/video/gr/gr-videoDisplay/build

# Utility rule file for videoDisplay_docstrings.

# Include any custom commands dependencies for this target.
include python/videoDisplay/bindings/CMakeFiles/videoDisplay_docstrings.dir/compiler_depend.make

# Include the progress variables for this target.
include python/videoDisplay/bindings/CMakeFiles/videoDisplay_docstrings.dir/progress.make

python/videoDisplay/bindings/CMakeFiles/videoDisplay_docstrings: python/videoDisplay/bindings/docstring_status

python/videoDisplay/bindings/docstring_status:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/rohit/Videos/video/gr/gr-videoDisplay/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Adding docstrings into videoDisplay pybind headers ..."
	cd /home/rohit/Videos/video/gr/gr-videoDisplay/build/python/videoDisplay/bindings && /home/rohit/radioconda/bin/python /home/rohit/Videos/video/gr/gr-videoDisplay/docs/doxygen/update_pydoc.py sub --json_path /home/rohit/Videos/video/gr/gr-videoDisplay/build/python/videoDisplay/bindings/extracted_docstrings.json --bindings_dir /home/rohit/Videos/video/gr/gr-videoDisplay/python/videoDisplay/bindings/docstrings --output_dir /home/rohit/Videos/video/gr/gr-videoDisplay/build/python/videoDisplay/bindings --filter gr::videoDisplay

videoDisplay_docstrings: python/videoDisplay/bindings/CMakeFiles/videoDisplay_docstrings
videoDisplay_docstrings: python/videoDisplay/bindings/docstring_status
videoDisplay_docstrings: python/videoDisplay/bindings/CMakeFiles/videoDisplay_docstrings.dir/build.make
.PHONY : videoDisplay_docstrings

# Rule to build all files generated by this target.
python/videoDisplay/bindings/CMakeFiles/videoDisplay_docstrings.dir/build: videoDisplay_docstrings
.PHONY : python/videoDisplay/bindings/CMakeFiles/videoDisplay_docstrings.dir/build

python/videoDisplay/bindings/CMakeFiles/videoDisplay_docstrings.dir/clean:
	cd /home/rohit/Videos/video/gr/gr-videoDisplay/build/python/videoDisplay/bindings && $(CMAKE_COMMAND) -P CMakeFiles/videoDisplay_docstrings.dir/cmake_clean.cmake
.PHONY : python/videoDisplay/bindings/CMakeFiles/videoDisplay_docstrings.dir/clean

python/videoDisplay/bindings/CMakeFiles/videoDisplay_docstrings.dir/depend:
	cd /home/rohit/Videos/video/gr/gr-videoDisplay/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rohit/Videos/video/gr/gr-videoDisplay /home/rohit/Videos/video/gr/gr-videoDisplay/python/videoDisplay/bindings /home/rohit/Videos/video/gr/gr-videoDisplay/build /home/rohit/Videos/video/gr/gr-videoDisplay/build/python/videoDisplay/bindings /home/rohit/Videos/video/gr/gr-videoDisplay/build/python/videoDisplay/bindings/CMakeFiles/videoDisplay_docstrings.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : python/videoDisplay/bindings/CMakeFiles/videoDisplay_docstrings.dir/depend

