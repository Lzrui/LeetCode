cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
add_executable(primer add.cc)
#if(WIN32)
#    target_link_libraries(leetcode wsock32 ws2_32)
#endif()