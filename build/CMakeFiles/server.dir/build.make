# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/tiki/Desktop/code/pro

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tiki/Desktop/code/pro/build

# Include any dependencies generated for this target.
include CMakeFiles/server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server.dir/flags.make

CMakeFiles/server.dir/src/ConnMgr.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/ConnMgr.cpp.o: ../src/ConnMgr.cpp
CMakeFiles/server.dir/src/ConnMgr.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiki/Desktop/code/pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/server.dir/src/ConnMgr.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/src/ConnMgr.cpp.o -MF CMakeFiles/server.dir/src/ConnMgr.cpp.o.d -o CMakeFiles/server.dir/src/ConnMgr.cpp.o -c /home/tiki/Desktop/code/pro/src/ConnMgr.cpp

CMakeFiles/server.dir/src/ConnMgr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/ConnMgr.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiki/Desktop/code/pro/src/ConnMgr.cpp > CMakeFiles/server.dir/src/ConnMgr.cpp.i

CMakeFiles/server.dir/src/ConnMgr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/ConnMgr.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiki/Desktop/code/pro/src/ConnMgr.cpp -o CMakeFiles/server.dir/src/ConnMgr.cpp.s

CMakeFiles/server.dir/src/DBConn.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/DBConn.cpp.o: ../src/DBConn.cpp
CMakeFiles/server.dir/src/DBConn.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiki/Desktop/code/pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/server.dir/src/DBConn.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/src/DBConn.cpp.o -MF CMakeFiles/server.dir/src/DBConn.cpp.o.d -o CMakeFiles/server.dir/src/DBConn.cpp.o -c /home/tiki/Desktop/code/pro/src/DBConn.cpp

CMakeFiles/server.dir/src/DBConn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/DBConn.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiki/Desktop/code/pro/src/DBConn.cpp > CMakeFiles/server.dir/src/DBConn.cpp.i

CMakeFiles/server.dir/src/DBConn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/DBConn.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiki/Desktop/code/pro/src/DBConn.cpp -o CMakeFiles/server.dir/src/DBConn.cpp.s

CMakeFiles/server.dir/src/DBConnPool.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/DBConnPool.cpp.o: ../src/DBConnPool.cpp
CMakeFiles/server.dir/src/DBConnPool.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiki/Desktop/code/pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/server.dir/src/DBConnPool.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/src/DBConnPool.cpp.o -MF CMakeFiles/server.dir/src/DBConnPool.cpp.o.d -o CMakeFiles/server.dir/src/DBConnPool.cpp.o -c /home/tiki/Desktop/code/pro/src/DBConnPool.cpp

CMakeFiles/server.dir/src/DBConnPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/DBConnPool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiki/Desktop/code/pro/src/DBConnPool.cpp > CMakeFiles/server.dir/src/DBConnPool.cpp.i

CMakeFiles/server.dir/src/DBConnPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/DBConnPool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiki/Desktop/code/pro/src/DBConnPool.cpp -o CMakeFiles/server.dir/src/DBConnPool.cpp.s

CMakeFiles/server.dir/src/EventThread.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/EventThread.cpp.o: ../src/EventThread.cpp
CMakeFiles/server.dir/src/EventThread.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiki/Desktop/code/pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/server.dir/src/EventThread.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/src/EventThread.cpp.o -MF CMakeFiles/server.dir/src/EventThread.cpp.o.d -o CMakeFiles/server.dir/src/EventThread.cpp.o -c /home/tiki/Desktop/code/pro/src/EventThread.cpp

CMakeFiles/server.dir/src/EventThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/EventThread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiki/Desktop/code/pro/src/EventThread.cpp > CMakeFiles/server.dir/src/EventThread.cpp.i

CMakeFiles/server.dir/src/EventThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/EventThread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiki/Desktop/code/pro/src/EventThread.cpp -o CMakeFiles/server.dir/src/EventThread.cpp.s

CMakeFiles/server.dir/src/Receiver.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/Receiver.cpp.o: ../src/Receiver.cpp
CMakeFiles/server.dir/src/Receiver.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiki/Desktop/code/pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/server.dir/src/Receiver.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/src/Receiver.cpp.o -MF CMakeFiles/server.dir/src/Receiver.cpp.o.d -o CMakeFiles/server.dir/src/Receiver.cpp.o -c /home/tiki/Desktop/code/pro/src/Receiver.cpp

CMakeFiles/server.dir/src/Receiver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/Receiver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiki/Desktop/code/pro/src/Receiver.cpp > CMakeFiles/server.dir/src/Receiver.cpp.i

CMakeFiles/server.dir/src/Receiver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/Receiver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiki/Desktop/code/pro/src/Receiver.cpp -o CMakeFiles/server.dir/src/Receiver.cpp.s

CMakeFiles/server.dir/src/RequestMgr.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/RequestMgr.cpp.o: ../src/RequestMgr.cpp
CMakeFiles/server.dir/src/RequestMgr.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiki/Desktop/code/pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/server.dir/src/RequestMgr.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/src/RequestMgr.cpp.o -MF CMakeFiles/server.dir/src/RequestMgr.cpp.o.d -o CMakeFiles/server.dir/src/RequestMgr.cpp.o -c /home/tiki/Desktop/code/pro/src/RequestMgr.cpp

CMakeFiles/server.dir/src/RequestMgr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/RequestMgr.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiki/Desktop/code/pro/src/RequestMgr.cpp > CMakeFiles/server.dir/src/RequestMgr.cpp.i

CMakeFiles/server.dir/src/RequestMgr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/RequestMgr.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiki/Desktop/code/pro/src/RequestMgr.cpp -o CMakeFiles/server.dir/src/RequestMgr.cpp.s

CMakeFiles/server.dir/src/Sender.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/Sender.cpp.o: ../src/Sender.cpp
CMakeFiles/server.dir/src/Sender.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiki/Desktop/code/pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/server.dir/src/Sender.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/src/Sender.cpp.o -MF CMakeFiles/server.dir/src/Sender.cpp.o.d -o CMakeFiles/server.dir/src/Sender.cpp.o -c /home/tiki/Desktop/code/pro/src/Sender.cpp

CMakeFiles/server.dir/src/Sender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/Sender.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiki/Desktop/code/pro/src/Sender.cpp > CMakeFiles/server.dir/src/Sender.cpp.i

CMakeFiles/server.dir/src/Sender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/Sender.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiki/Desktop/code/pro/src/Sender.cpp -o CMakeFiles/server.dir/src/Sender.cpp.s

CMakeFiles/server.dir/src/Server.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/Server.cpp.o: ../src/Server.cpp
CMakeFiles/server.dir/src/Server.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiki/Desktop/code/pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/server.dir/src/Server.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/src/Server.cpp.o -MF CMakeFiles/server.dir/src/Server.cpp.o.d -o CMakeFiles/server.dir/src/Server.cpp.o -c /home/tiki/Desktop/code/pro/src/Server.cpp

CMakeFiles/server.dir/src/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiki/Desktop/code/pro/src/Server.cpp > CMakeFiles/server.dir/src/Server.cpp.i

CMakeFiles/server.dir/src/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiki/Desktop/code/pro/src/Server.cpp -o CMakeFiles/server.dir/src/Server.cpp.s

CMakeFiles/server.dir/src/ThreadPool.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/ThreadPool.cpp.o: ../src/ThreadPool.cpp
CMakeFiles/server.dir/src/ThreadPool.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiki/Desktop/code/pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/server.dir/src/ThreadPool.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/src/ThreadPool.cpp.o -MF CMakeFiles/server.dir/src/ThreadPool.cpp.o.d -o CMakeFiles/server.dir/src/ThreadPool.cpp.o -c /home/tiki/Desktop/code/pro/src/ThreadPool.cpp

CMakeFiles/server.dir/src/ThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/ThreadPool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiki/Desktop/code/pro/src/ThreadPool.cpp > CMakeFiles/server.dir/src/ThreadPool.cpp.i

CMakeFiles/server.dir/src/ThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/ThreadPool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiki/Desktop/code/pro/src/ThreadPool.cpp -o CMakeFiles/server.dir/src/ThreadPool.cpp.s

CMakeFiles/server.dir/src/base64.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/base64.cpp.o: ../src/base64.cpp
CMakeFiles/server.dir/src/base64.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiki/Desktop/code/pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/server.dir/src/base64.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/src/base64.cpp.o -MF CMakeFiles/server.dir/src/base64.cpp.o.d -o CMakeFiles/server.dir/src/base64.cpp.o -c /home/tiki/Desktop/code/pro/src/base64.cpp

CMakeFiles/server.dir/src/base64.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/base64.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiki/Desktop/code/pro/src/base64.cpp > CMakeFiles/server.dir/src/base64.cpp.i

CMakeFiles/server.dir/src/base64.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/base64.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiki/Desktop/code/pro/src/base64.cpp -o CMakeFiles/server.dir/src/base64.cpp.s

CMakeFiles/server.dir/src/main.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/server.dir/src/main.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiki/Desktop/code/pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/server.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/src/main.cpp.o -MF CMakeFiles/server.dir/src/main.cpp.o.d -o CMakeFiles/server.dir/src/main.cpp.o -c /home/tiki/Desktop/code/pro/src/main.cpp

CMakeFiles/server.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiki/Desktop/code/pro/src/main.cpp > CMakeFiles/server.dir/src/main.cpp.i

CMakeFiles/server.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiki/Desktop/code/pro/src/main.cpp -o CMakeFiles/server.dir/src/main.cpp.s

CMakeFiles/server.dir/src/md5.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/md5.cpp.o: ../src/md5.cpp
CMakeFiles/server.dir/src/md5.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiki/Desktop/code/pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/server.dir/src/md5.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/src/md5.cpp.o -MF CMakeFiles/server.dir/src/md5.cpp.o.d -o CMakeFiles/server.dir/src/md5.cpp.o -c /home/tiki/Desktop/code/pro/src/md5.cpp

CMakeFiles/server.dir/src/md5.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/md5.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiki/Desktop/code/pro/src/md5.cpp > CMakeFiles/server.dir/src/md5.cpp.i

CMakeFiles/server.dir/src/md5.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/md5.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiki/Desktop/code/pro/src/md5.cpp -o CMakeFiles/server.dir/src/md5.cpp.s

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/src/ConnMgr.cpp.o" \
"CMakeFiles/server.dir/src/DBConn.cpp.o" \
"CMakeFiles/server.dir/src/DBConnPool.cpp.o" \
"CMakeFiles/server.dir/src/EventThread.cpp.o" \
"CMakeFiles/server.dir/src/Receiver.cpp.o" \
"CMakeFiles/server.dir/src/RequestMgr.cpp.o" \
"CMakeFiles/server.dir/src/Sender.cpp.o" \
"CMakeFiles/server.dir/src/Server.cpp.o" \
"CMakeFiles/server.dir/src/ThreadPool.cpp.o" \
"CMakeFiles/server.dir/src/base64.cpp.o" \
"CMakeFiles/server.dir/src/main.cpp.o" \
"CMakeFiles/server.dir/src/md5.cpp.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

../bin/server: CMakeFiles/server.dir/src/ConnMgr.cpp.o
../bin/server: CMakeFiles/server.dir/src/DBConn.cpp.o
../bin/server: CMakeFiles/server.dir/src/DBConnPool.cpp.o
../bin/server: CMakeFiles/server.dir/src/EventThread.cpp.o
../bin/server: CMakeFiles/server.dir/src/Receiver.cpp.o
../bin/server: CMakeFiles/server.dir/src/RequestMgr.cpp.o
../bin/server: CMakeFiles/server.dir/src/Sender.cpp.o
../bin/server: CMakeFiles/server.dir/src/Server.cpp.o
../bin/server: CMakeFiles/server.dir/src/ThreadPool.cpp.o
../bin/server: CMakeFiles/server.dir/src/base64.cpp.o
../bin/server: CMakeFiles/server.dir/src/main.cpp.o
../bin/server: CMakeFiles/server.dir/src/md5.cpp.o
../bin/server: CMakeFiles/server.dir/build.make
../bin/server: CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tiki/Desktop/code/pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable ../bin/server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server.dir/build: ../bin/server
.PHONY : CMakeFiles/server.dir/build

CMakeFiles/server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server.dir/clean

CMakeFiles/server.dir/depend:
	cd /home/tiki/Desktop/code/pro/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tiki/Desktop/code/pro /home/tiki/Desktop/code/pro /home/tiki/Desktop/code/pro/build /home/tiki/Desktop/code/pro/build /home/tiki/Desktop/code/pro/build/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server.dir/depend

