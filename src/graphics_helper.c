#include "graphics_helper.h"

void get_errors() {
  switch (glGetError()) {
	case GL_NO_ERROR:break;
	case GL_INVALID_ENUM:printf("GL_INVALID_ENUM\n");
	  break;
	case GL_INVALID_VALUE:printf("GL_INVALID_VALUE\n");
	  break;
	case GL_INVALID_OPERATION:printf("GL_INVALID_OPERATION\n");
	  break;
	case GL_INVALID_FRAMEBUFFER_OPERATION:printf("GL_INVALID_FRAMEBUFFER_OPERATION\n");
	  break;
	case GL_OUT_OF_MEMORY:printf("GL_OUT_OF_MEMORY\n");
	  break;
	case GL_STACK_UNDERFLOW:printf("GL_STACK_UNDERFLOW\n");
	  break;
	case GL_STACK_OVERFLOW:printf("GL_STACK_OVERFLOW\n");
	  break;
	default:printf("UNKNOWN\n");
	  break;
  }
}
