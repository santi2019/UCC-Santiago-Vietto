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
include CMakeFiles/Ej7.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Ej7.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Ej7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ej7.dir/flags.make

CMakeFiles/Ej7.dir/Ej7.cpp.obj: CMakeFiles/Ej7.dir/flags.make
CMakeFiles/Ej7.dir/Ej7.cpp.obj: ../Ej7.cpp
CMakeFiles/Ej7.dir/Ej7.cpp.obj: CMakeFiles/Ej7.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Santiago\Documentos\UCC-Santi\2do\Programacion 3\Ejercicios\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Ej7.dir/Ej7.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ej7.dir/Ej7.cpp.obj -MF CMakeFiles\Ej7.dir\Ej7.cpp.obj.d -o CMakeFiles\Ej7.dir\Ej7.cpp.obj -c "D:\Santiago\Documentos\UCC-Santi\2do\Programacion 3\Ejercicios\Ej7.cpp"

CMakeFiles/Ej7.dir/Ej7.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ej7.dir/Ej7.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Santiago\Documentos\UCC-Santi\2do\Programacion 3\Ejercicios\Ej7.cpp" > CMakeFiles\Ej7.dir\Ej7.cpp.i

CMakeFiles/Ej7.dir/Ej7.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ej7.dir/Ej7.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Santiago\Documentos\UCC-Santi\2do\Programacion 3\Ejercicios\Ej7.cpp" -o CMakeFiles\Ej7.dir\Ej7.cpp.s

# Object files for target Ej7
Ej7_OBJECTS = \
"CMakeFiles/Ej7.dir/Ej7.cpp.obj"

# External object files for target Ej7
Ej7_EXTERNAL_OBJECTS =

Ej7.exe: CMakeFiles/Ej7.dir/Ej7.cpp.obj
Ej7.exe: CMakeFiles/Ej7.dir/build.make
Ej7.exe: CMakeFiles/Ej7.dir/linklibs.rsp
Ej7.exe: CMakeFiles/Ej7.dir/objects1.rsp
Ej7.exe: CMakeFiles/Ej7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Santiago\Documentos\UCC-Santi\2do\Programacion 3\Ejercicios\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Ej7.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Ej7.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ej7.dir/build: Ej7.exe
.PHONY : CMakeFiles/Ej7.dir/build

CMakeFiles/Ej7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Ej7.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Ej7.dir/clean

CMakeFiles/Ej7.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Santiago\Documentos\UCC-Santi\2do\Programacion 3\Ejercicios" "D:\Santiago\Documentos\UCC-Santi\2do\Programacion 3\Ejercicios" "D:\Santiago\Documentos\UCC-Santi\2do\Programacion 3\Ejercicios\cmake-build-debug" "D:\Santiago\Documentos\UCC-Santi\2do\Programacion 3\Ejercicios\cmake-build-debug" "D:\Santiago\Documentos\UCC-Santi\2do\Programacion 3\Ejercicios\cmake-build-debug\CMakeFiles\Ej7.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Ej7.dir/depend

