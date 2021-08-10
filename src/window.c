#include "window.h"

struct window {
  int width;
  int height;
  float x_scale;
  float y_scale;
  const char *name;
  GLFWwindow *glfw_window;
};

window_t *create_window(int width, int height, const char *window_name) {
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  GLFWwindow *glfw_window = glfwCreateWindow(width, height, window_name, NULL, NULL);
  if (glfw_window == NULL) {
	fprintf(stderr, "error creating glfw_window\n");
	glfwTerminate();
	exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(glfw_window);

  float x_scale, y_scale;
  glfwGetWindowContentScale(glfw_window, &x_scale, &y_scale);

  window_t *window = (window_t *) malloc(sizeof(window_t));
  window->width = width;
  window->height = height;
  window->x_scale = x_scale;
  window->y_scale = y_scale;
  window->glfw_window = glfw_window;
  return window;
}

int should_window_close(window_t *window) {
  return glfwWindowShouldClose(window->glfw_window);
}

void clean_up_window(window_t *window) {
  glfwDestroyWindow(window->glfw_window);
}

int get_window_width(window_t *window) {
  return window->width;
}

int get_window_height(window_t *window) {
  return window->height;
}

float get_window_x_scale(window_t *window) {
  return window->x_scale;
}

float get_window_y_scale(window_t *window) {
  return window->y_scale;
}

GLFWwindow *get_window(window_t *window) {
  return window->glfw_window;
}

void swap_buffers(window_t *window) {
  glfwSwapBuffers(get_window(window));
}
