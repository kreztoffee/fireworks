#ifndef __GRAPHICS_HELPERS_H__
#define __GRAPHICS_HELPERS_H__

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

#endif /* __GRAPHICS_HELPERS_H__ */
