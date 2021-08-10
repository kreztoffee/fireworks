#include "keyboard_handler.h"

void init_keyboard_handler(window_t *window) {
  glfwSetKeyCallback(get_window(window), key_callback);
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
  scancode = 0;
  mods = 0;
  window = NULL;
  //GLFWwindow *window = get_window(window);

  if (key == GLFW_KEY_W && action == GLFW_PRESS) {
  } else if (key == GLFW_KEY_S && action == GLFW_PRESS) {
  } else if (key == GLFW_KEY_A && action == GLFW_PRESS) {
  } else if (key == GLFW_KEY_D && action == GLFW_PRESS) {
  }
}
