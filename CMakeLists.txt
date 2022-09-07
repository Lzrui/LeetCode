cmake_minimum_required(VERSION 3.21)
project(leetcode_cookbook)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
add_executable(leetcode test.cpp MyTrie.cpp)

#if(WIN32)
#    target_link_libraries(leetcode wsock32 ws2_32)
#endif()