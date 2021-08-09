#ifndef GRAPHICS_HELPER_H__
#define GRAPHICS_HELPER_H__

#ifdef WIN32
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#else
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#endif

#include "window.h"
#include <stdio.h>

void get_errors();

#endif /* GRAPHICS_HELPER_H__ */
