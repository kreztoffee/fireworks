#include "control.h"

void handle_input(window_t* window) {
	GLFWwindow* glfw_window = get_window(window);

	int state = glfwGetKey(glfw_window, GLFW_KEY_A);
	if (state == GLFW_PRESS) {
	}

	state = glfwGetKey(glfw_window, GLFW_KEY_D);
	if (state == GLFW_PRESS) {
	}

	state = glfwGetKey(glfw_window, GLFW_KEY_S);
	if (state == GLFW_PRESS) {
	}

	state = glfwGetKey(glfw_window, GLFW_KEY_SPACE);
	if (state == GLFW_PRESS) {
	}
}
