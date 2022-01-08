cmake_minimum_required(VERSION 3.21)
project(LearnOpenGL)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp glad.c)
add_executable(LearnOpenGL ${SOURCE_FILES})
target_link_libraries(LearnOpenGL glfw3 GL m Xrandr Xi X11 Xxf86vm pthread dl Xinerama Xcursor)