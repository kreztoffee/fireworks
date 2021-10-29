#include "framework_helpers.h"
#include "graphics_helpers.h"

void init_glew() {
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "error initializing glew\n");
		exit(EXIT_FAILURE);
	}
}

void init_glfw() {
	if (glfwInit() != GLFW_TRUE) {
		fprintf(stderr, "error initializing glfw\n");
		exit(EXIT_FAILURE);
	}
}
