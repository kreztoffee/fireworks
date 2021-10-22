#include "graphics_helpers.h"
#include "keyboard_handler.h"
#include "mouse_handler.h"
#include "framework_helpers.h"
#include "control.h"
#include "event.h"
#include "window.h"
#include "particle.h"
#include "time_fw.h"
#include <stdlib.h>

#define WIDTH 640
#define HEIGHT 480

int main() {
	init_glfw();
	window_t* window = create_window(WIDTH, HEIGHT, "fireworks");
	struct time_fw* time_fw = (struct time_fw*)malloc(sizeof(struct time_fw));
	init_glew();

	init_keyboard_handler(window);
	init_mouse_handler(window);

	init_time_fw(time_fw);

	poll_events();
	while (!should_window_close(window)) {
		step_time_fw(time_fw);

		handle_input(window);

		/* render stuff */
		const GLfloat clear_color[] = {0.2f, 0.2f, 0.5f, 1.0f};
		glClearBufferfv(GL_COLOR, 0, clear_color);
		render_particles();

		swap_buffers(window);
		/*print_time_fw(time_fw);*/
		poll_events();
	}

	clean_up_window(window);
	glfwTerminate();

	exit(EXIT_SUCCESS);
}
