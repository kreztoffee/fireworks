#include "graphics_helper.h"
#include "keyboard_handler.h"
#include "mouse_handler.h"
#include "control.h"
#include "event.h"
#include "window.h"
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 640
#define HEIGHT 480
#define MS_PER_UPDATE 10

int main() {
  window_t *window;
  double prev_ms, lag, cur_ms, delta_ms;

  if (glfwInit() != GLFW_TRUE) {
	fprintf(stderr, "error initializing glfw\n");
	exit(EXIT_FAILURE);
  }

  window = create_window(WIDTH, HEIGHT, "fireworks");
  init_keyboard_handler(window);
  init_mouse_handler(window);

  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) {
	fprintf(stderr, "error initializing glew\n");
	exit(EXIT_FAILURE);
  }

  prev_ms = glfwGetTime();
  lag = 0.0;

  poll_events();
  while (!should_window_close(window)) {
	cur_ms = glfwGetTime();
	delta_ms = (cur_ms - prev_ms) * 1000.0;
	lag += delta_ms;

	handle_input(window);

	while (lag >= MS_PER_UPDATE) {
	  //update(MS_PER_UPDATE);
	  lag -= MS_PER_UPDATE;
	}

	// render stuff
	// render stuff
	const GLfloat clear_color[] = {0.2f, 0.2f, 0.5f, 1.0f};
	glClearBufferfv(GL_COLOR, 0, clear_color);

	swap_buffers(window);

	poll_events();
	prev_ms = cur_ms;
  }

  clean_up_window(window);
  glfwTerminate();

  exit(EXIT_SUCCESS);
}
