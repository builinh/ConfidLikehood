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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/builinh/Dropbox/SEASTAR2017/Linh_code_DTCB2021/ConfiLikelihood

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/builinh/Dropbox/SEASTAR2017/Linh_code_DTCB2021/ConfiLikelihood/build

# Include any dependencies generated for this target.
include CMakeFiles/ConfiLikelihood.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ConfiLikelihood.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ConfiLikelihood.dir/flags.make

CMakeFiles/ConfiLikelihood.dir/main.cxx.o: CMakeFiles/ConfiLikelihood.dir/flags.make
CMakeFiles/ConfiLikelihood.dir/main.cxx.o: ../main.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/builinh/Dropbox/SEASTAR2017/Linh_code_DTCB2021/ConfiLikelihood/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ConfiLikelihood.dir/main.cxx.o"
	/usr/bin/clang++-3.5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ConfiLikelihood.dir/main.cxx.o -c /home/builinh/Dropbox/SEASTAR2017/Linh_code_DTCB2021/ConfiLikelihood/main.cxx

CMakeFiles/ConfiLikelihood.dir/main.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ConfiLikelihood.dir/main.cxx.i"
	/usr/bin/clang++-3.5 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/builinh/Dropbox/SEASTAR2017/Linh_code_DTCB2021/ConfiLikelihood/main.cxx > CMakeFiles/ConfiLikelihood.dir/main.cxx.i

CMakeFiles/ConfiLikelihood.dir/main.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ConfiLikelihood.dir/main.cxx.s"
	/usr/bin/clang++-3.5 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/builinh/Dropbox/SEASTAR2017/Linh_code_DTCB2021/ConfiLikelihood/main.cxx -o CMakeFiles/ConfiLikelihood.dir/main.cxx.s

CMakeFiles/ConfiLikelihood.dir/main.cxx.o.requires:

.PHONY : CMakeFiles/ConfiLikelihood.dir/main.cxx.o.requires

CMakeFiles/ConfiLikelihood.dir/main.cxx.o.provides: CMakeFiles/ConfiLikelihood.dir/main.cxx.o.requires
	$(MAKE) -f CMakeFiles/ConfiLikelihood.dir/build.make CMakeFiles/ConfiLikelihood.dir/main.cxx.o.provides.build
.PHONY : CMakeFiles/ConfiLikelihood.dir/main.cxx.o.provides

CMakeFiles/ConfiLikelihood.dir/main.cxx.o.provides.build: CMakeFiles/ConfiLikelihood.dir/main.cxx.o


# Object files for target ConfiLikelihood
ConfiLikelihood_OBJECTS = \
"CMakeFiles/ConfiLikelihood.dir/main.cxx.o"

# External object files for target ConfiLikelihood
ConfiLikelihood_EXTERNAL_OBJECTS =

ConfiLikelihood: CMakeFiles/ConfiLikelihood.dir/main.cxx.o
ConfiLikelihood: CMakeFiles/ConfiLikelihood.dir/build.make
ConfiLikelihood: libConfidenceLikelihood.so
ConfiLikelihood: /home/builinh/Program/root6/lib/libCore.so
ConfiLikelihood: /home/builinh/Program/root6/lib/libImt.so
ConfiLikelihood: /home/builinh/Program/root6/lib/libRIO.so
ConfiLikelihood: /home/builinh/Program/root6/lib/libNet.so
ConfiLikelihood: /home/builinh/Program/root6/lib/libHist.so
ConfiLikelihood: /home/builinh/Program/root6/lib/libGraf.so
ConfiLikelihood: /home/builinh/Program/root6/lib/libGraf3d.so
ConfiLikelihood: /home/builinh/Program/root6/lib/libGpad.so
ConfiLikelihood: /home/builinh/Program/root6/lib/libROOTDataFrame.so
ConfiLikelihood: /home/builinh/Program/root6/lib/libTree.so
ConfiLikelihood: /home/builinh/Program/root6/lib/libTreePlayer.so
ConfiLikelihood: /home/builinh/Program/root6/lib/libRint.so
ConfiLikelihood: /home/builinh/Program/root6/lib/libPostscript.so
ConfiLikelihood: /home/builinh/Program/root6/lib/libMatrix.so
ConfiLikelihood: /home/builinh/Program/root6/lib/libPhysics.so
ConfiLikelihood: /home/builinh/Program/root6/lib/libMathCore.so
ConfiLikelihood: /home/builinh/Program/root6/lib/libThread.so
ConfiLikelihood: /home/builinh/Program/root6/lib/libMultiProc.so
ConfiLikelihood: /home/builinh/Program/root6/lib/libGui.so
ConfiLikelihood: CMakeFiles/ConfiLikelihood.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/builinh/Dropbox/SEASTAR2017/Linh_code_DTCB2021/ConfiLikelihood/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ConfiLikelihood"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ConfiLikelihood.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ConfiLikelihood.dir/build: ConfiLikelihood

.PHONY : CMakeFiles/ConfiLikelihood.dir/build

CMakeFiles/ConfiLikelihood.dir/requires: CMakeFiles/ConfiLikelihood.dir/main.cxx.o.requires

.PHONY : CMakeFiles/ConfiLikelihood.dir/requires

CMakeFiles/ConfiLikelihood.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ConfiLikelihood.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ConfiLikelihood.dir/clean

CMakeFiles/ConfiLikelihood.dir/depend:
	cd /home/builinh/Dropbox/SEASTAR2017/Linh_code_DTCB2021/ConfiLikelihood/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/builinh/Dropbox/SEASTAR2017/Linh_code_DTCB2021/ConfiLikelihood /home/builinh/Dropbox/SEASTAR2017/Linh_code_DTCB2021/ConfiLikelihood /home/builinh/Dropbox/SEASTAR2017/Linh_code_DTCB2021/ConfiLikelihood/build /home/builinh/Dropbox/SEASTAR2017/Linh_code_DTCB2021/ConfiLikelihood/build /home/builinh/Dropbox/SEASTAR2017/Linh_code_DTCB2021/ConfiLikelihood/build/CMakeFiles/ConfiLikelihood.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ConfiLikelihood.dir/depend

