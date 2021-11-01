cmake_minimum_required(VERSION 3.20)

project(fireworks C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_BUILD_TYPE Debug)

add_executable(fireworks)
target_sources(fireworks PRIVATE
        main.c)

find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GSL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

add_subdirectory(src)
target_compile_options(fireworks PUBLIC -g -Wall -Wextra -Wpedantic -MMD -MP -Qunused-arguments)
target_include_directories(fireworks PUBLIC
        include
        ${OPENGL_INCLUDE_DIRS}
        ${GLEW_INCLUDE_DIRS})
target_link_libraries(fireworks PUBLIC
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARIES}
        glfw)
