#include "shader.h"
#include <string.h>

GLuint load_shader(const char* filename) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		exit(EXIT_FAILURE);
	}

	fseek(fp, 0, SEEK_END);
	size_t len = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	char* src = (char*) malloc(len + 1);
	memset(src, 0, len + 1);
	fread(src, 1, len, fp);

	const char* ext = get_file_extension(filename);

	GLint id = 0;
	if (strcmp(ext, "vert") == 0) {
		id = glCreateShader(GL_VERTEX_SHADER);
	} else if (strcmp(ext, "frag") == 0) {
		id = glCreateShader(GL_FRAGMENT_SHADER);
	} else {
		fprintf(stderr, "unknown extension %s\n", ext);
	}

	if (id > 0) {
		compile_shader(id, (const GLchar*) src);
		check_shader_for_errors(id);
	}

	free(src);
	fclose(fp);
	return id;
}

const char* get_file_extension(const char* filename) {
	const char* ext = strrchr(filename, '.');
	if (ext == NULL) {
		return ext;
	}
	return ext + 1;
}

void compile_shader(GLuint id, const GLchar* src) {
	if (id > 0) {
		glShaderSource(id, 1, &src, NULL);
		glCompileShader(id);
	}
}

void check_shader_for_errors(GLuint id) {
	GLint res = GL_FALSE;
	glGetShaderiv(id, GL_COMPILE_STATUS, &res);
	if (res == GL_FALSE) {
		int log_length = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &log_length);
		char* err_msg = (char*) malloc(log_length * sizeof(char));
		glGetShaderInfoLog(id, log_length, NULL, err_msg);
		fprintf(stderr, "%s\n", err_msg);
		free(err_msg);
		glDeleteShader(id);
	}
}

GLuint create_program(GLuint* shader_ids, uint32_t num_shaders) {
	GLuint prog_id = 0;

	if (num_shaders == 0) {
		fprintf(stderr, "no shaders to link\n");
		return prog_id;
	}

	prog_id = glCreateProgram();
	if (prog_id > 0) {
		for (uint32_t i = 0; i < num_shaders; ++i) {
			glAttachShader(prog_id, shader_ids[i]);
		}

		glLinkProgram(prog_id);
		check_program_for_errors(prog_id);

		for (uint32_t i = 0; i < num_shaders; ++i) {
			glDeleteShader(shader_ids[i]);
		}
	}
	return prog_id;
}

void check_program_for_errors(GLuint prog_id) {
	GLint res = GL_FALSE;
	glGetProgramiv(prog_id, GL_LINK_STATUS, &res);
	if (res == GL_FALSE) {
		int log_length = 0;
		glGetProgramiv(prog_id, GL_INFO_LOG_LENGTH, &log_length);
		char* err_msg = (char*) malloc(log_length * sizeof(char));
		glGetProgramInfoLog(prog_id, log_length, NULL, err_msg);
		fprintf(stderr, "%s\n", err_msg);
		free(err_msg);
		glDeleteProgram(prog_id);
	}
}

void load_matrix(GLuint prog_id, const char* uniform_id, gsl_matrix* mat) {
	const int elements = mat->size1 * mat->size2;
	float matrixBuffer[elements];
	GLuint uniform_id_loc = glGetUniformLocation(prog_id, uniform_id);
	for (int i = 0; i < elements; i++) {
		matrixBuffer[i] = (float) mat->data[i];
	}
	glUniformMatrix4fv(uniform_id_loc, 1, GL_FALSE, (const GLfloat*) matrixBuffer);
}
