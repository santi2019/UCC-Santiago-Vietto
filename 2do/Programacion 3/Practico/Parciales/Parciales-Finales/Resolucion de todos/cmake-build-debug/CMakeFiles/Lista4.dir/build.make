# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Santiago\Documentos\UCC-Santi\2do\Programacion 3\Ejercicios"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Santiago\Documentos\UCC-Santi\2do\Programacion 3\Ejercicios\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Lista4.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Lista4.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Lista4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lista4.dir/flags.make

CMakeFiles/Lista4.dir/Lista4.cpp.obj: CMakeFiles/Lista4.dir/flags.make
CMakeFiles/Lista4.dir/Lista4.cpp.obj: ../Lista4.cpp
CMakeFiles/Lista4.dir/Lista4.cpp.obj: CMakeFiles/Lista4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Santiago\Documentos\UCC-Santi\2do\Programacion 3\Ejercicios\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lista4.dir/Lista4.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Lista4.dir/Lista4.cpp.obj -MF CMakeFiles\Lista4.dir\Lista4.cpp.obj.d -o CMakeFiles\Lista4.dir\Lista4.cpp.obj -c "D:\Santiago\Documentos\UCC-Santi\2do\Programacion 3\Ejercicios\Lista4.cpp"

CMakeFiles/Lista4.dir/Lista4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lista4.dir/Lista4.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Santiago\Documentos\UCC-Santi\2do\Programacion 3\Ejercicios\Lista4.cpp" > CMakeFiles\Lista4.dir\Lista4.cpp.i

CMakeFiles/Lista4.dir/Lista4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lista4.dir/Lista4.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Santiago\Documentos\UCC-Santi\2do\Programacion 3\Ejercicios\Lista4.cpp" -o CMakeFiles\Lista4.dir\Lista4.cpp.s

# Object files for target Lista4
Lista4_OBJECTS = \
"CMakeFiles/Lista4.dir/Lista4.cpp.obj"

# External object files for target Lista4
Lista4_EXTERNAL_OBJECTS =

Lista4.exe: CMakeFiles/Lista4.dir/Lista4.cpp.obj
Lista4.exe: CMakeFiles/Lista4.dir/build.make
Lista4.exe: CMakeFiles/Lista4.dir/linklibs.rsp
Lista4.exe: CMakeFiles/Lista4.dir/objects1.rsp
Lista4.exe: CMakeFiles/Lista4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Santiago\Documentos\UCC-Santi\2do\Programacion 3\Ejercicios\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lista4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lista4.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lista4.dir/build: Lista4.exe
.PHONY : CMakeFiles/Lista4.dir/build

CMakeFiles/Lista4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lista4.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lista4.dir/clean

CMakeFiles/Lista4.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Santiago\Documentos\UCC-Santi\2do\Programacion 3\Ejercicios" "D:\Santiago\Documentos\UCC-Santi\2do\Programacion 3\Ejercicios" "D:\Santiago\Documentos\UCC-Santi\2do\Programacion 3\Ejercicios\cmake-build-debug" "D:\Santiago\Documentos\UCC-Santi\2do\Programacion 3\Ejercicios\cmake-build-debug" "D:\Santiago\Documentos\UCC-Santi\2do\Programacion 3\Ejercicios\cmake-build-debug\CMakeFiles\Lista4.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Lista4.dir/depend

