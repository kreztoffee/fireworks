#include "renderer.h"
#include <gsl/gsl_matrix.h>
#include "transform.h"

void prepare_renderer(GLuint basic_prog_id, window_t* window) {
	float width = (float) get_window_width(window)/* * get_window_x_scale(window)*/;
	float height = (float) get_window_height(window)/* * get_window_y_scale(window)*/;
	glViewport(0, 0, (int) width, (int) height);
	glUseProgram(basic_prog_id);
	gsl_matrix* proj_mat = orth_proj_mat(0, width, 0, height, -1.0f, 1.0f);
	load_matrix(basic_prog_id, "proj", proj_mat);
}
