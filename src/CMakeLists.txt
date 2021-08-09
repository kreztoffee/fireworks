file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.c)

add_executable(fireworks)
target_sources(fireworks PRIVATE ${SRC_FILES})

target_compile_options(fireworks PUBLIC -g -Wall -Wextra -Wpedantic -MMD -MP -Qunused-arguments)

target_include_directories(fireworks PUBLIC ${PROJECT_SOURCE_DIR}/include)

find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GSL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
target_include_directories(fireworks PUBLIC ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})
target_link_libraries(fireworks PUBLIC ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARIES} glfw GSL::gsl GSL::gslcblas)

IF(APPLE)
    find_library(COCOA_LIBRARY Cocoa REQUIRED)
    find_library(COCOA_LIBRARY IOKit REQUIRED)
    target_link_libraries(fireworks PUBLIC ${COCOA_LIBRARY} ${IOKIT_LIBRARY})
ENDIF(APPLE)

target_link_libraries(fireworks PUBLIC m)

#install(TARGETS fireworks DESTINATION ${PROJECT_SOURCE_DIR}/bin)
#install(FILES ${PROJECT_SOURCE_DIR}/include DESTINATION include)