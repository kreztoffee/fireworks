#ifndef __SHADER_H__
#define __SHADER_H__

#include <stdio.h>
#include <stdlib.h>

#include <gsl/gsl_matrix.h>
#include "graphics_helpers.h"

GLuint load_shader(const char* filename);
void compile_shader(GLuint id, const GLchar* src);
const char* get_file_extension(const char* filename);
void check_shader_for_errors(GLuint id);

GLuint create_program(GLuint* shader_ids, uint32_t num_shaders);
void check_program_for_errors(GLuint prog_id);

void load_matrix(GLuint prog_id, const char* uniform_id, gsl_matrix* mat);
void load_float(GLuint prog_id, const char* uniform_id, float val);
void load_float_array(GLuint prog_id, const char* uniform_id, float* val, int elems);
void load_int(GLuint prog_id, const char* uniform_id, int val);

#endif /* __SHADER_H__ */
