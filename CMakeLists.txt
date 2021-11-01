cmake_minimum_required(VERSION 3.20)

project(fireworks C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_BUILD_TYPE Debug)

add_executable(fireworks)
target_sources(fireworks PRIVATE
        main.c)

find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GSL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)
target_compile_options(fireworks PUBLIC -Wall -Wextra -Wpedantic)
target_include_directories(fireworks PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        ${GLEW_INCLUDE_DIR}
        ${OPENGL_INCLUDE_DIR}
        ${GSL_INCLUDE_DIR})
target_link_libraries(fireworks PUBLIC
        ${GLEW_LIBRARIES}
        ${OPENGL_LIBRARIES}
        ${GSL_LIBRARIES}
        glfw)
