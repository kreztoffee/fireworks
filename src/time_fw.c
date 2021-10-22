#include "time_fw.h"
#include "graphics_helpers.h"

void init_time_fw(struct time_fw* time_fw) {
	time_fw->prev_ms = 0.0;
	time_fw->lag = 0.0;
	time_fw->cur_ms = glfwGetTime();
	time_fw->delta_ms = 0.0;
}

void step_time_fw(struct time_fw* time_fw) {
	double now = glfwGetTime();
	time_fw->delta_ms = (now - time_fw->prev_ms);
	time_fw->prev_ms = time_fw->cur_ms;
	time_fw->cur_ms = now;
	/*time_fw->lag += time_fw->delta_ms;

	while (time_fw->lag >= MS_PER_UPDATE) {
		time_fw->lag -= MS_PER_UPDATE;
	}*/
}

void print_time_fw(struct time_fw* time_fw) {
	printf("Current: %f\n", time_fw->cur_ms);
	printf("Previous: %f\n", time_fw->prev_ms);
	printf("Delta: %f\n", time_fw->delta_ms);
	/*printf("Lag: %f\n", time_fw->lag);*/
}
