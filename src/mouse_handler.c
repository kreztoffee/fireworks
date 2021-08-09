#include "mouse_handler.h"

void init_mouse_handler(window_t *window) {
  glfwSetMouseButtonCallback(get_window(window), mouse_button_callback);
}

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {
  mods = 0;
  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	printf("%f %f\n", xpos, ypos);
  }
}
