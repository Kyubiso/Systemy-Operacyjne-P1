cmake_minimum_required(VERSION 3.28)
project(ProjectSO)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 17)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(ProjectSO main.cpp
        src/Customer.cpp
        src/Customer.h
        src/Station.cpp
        src/Station.h
        src/Visualiser.cpp
        src/Visualiser.h
        src/CustomerGenerator.cpp
        src/CustomerGenerator.h
)
target_compile_options(ProjectSO PRIVATE -std=c++11 -Wall -Wextra)
target_link_libraries(ProjectSO PRIVATE GLEW glfw GL ${CURSES_LIBRARIES})
