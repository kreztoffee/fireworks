#include "graphics_helpers.h"
#include "keyboard_handler.h"
#include "mouse_handler.h"
#include "framework_helpers.h"
#include "event.h"
#include "window.h"
#include "particle.h"
#include "time_fw.h"
#include "shader.h"

#include "renderer.h"

#include <stdlib.h>

#define WIDTH 640
#define HEIGHT 480

int main() {
	init_glfw();
	window_t* window = create_window(WIDTH, HEIGHT, "fireworks");
	struct time_fw* time_fw = init_time_fw();
	init_glew();

	init_keyboard_handler(window);
	init_mouse_handler(window);
	init_particle_system();

	GLuint shader_stages[2];
	shader_stages[0] = load_shader("../res/basic_shader_2d.vert");
	shader_stages[1] = load_shader("../res/basic_shader_2d.frag");
	GLuint basic_prog_id = create_program(&shader_stages[0], 2);

	prepare_renderer(basic_prog_id, window);

	poll_events();
	while (!should_window_close(window)) {
		step_time_fw(time_fw);

		const GLfloat clear_color[] = {0.01f, 0.01f, 0.1f, 1.0f};
		glClearBufferfv(GL_COLOR, 0, clear_color);
		while (time_fw->lag >= MS_PER_UPDATE) {
			time_fw->lag -= MS_PER_UPDATE;
			update_particles(MS_PER_UPDATE / 1000.0f);
		}
		render_particles(basic_prog_id);

		swap_buffers(window);
		print_time_fw(time_fw);
		poll_events();
	}

	clean_up_window(window);
	glfwTerminate();

	exit(EXIT_SUCCESS);
}
