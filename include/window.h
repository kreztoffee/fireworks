#ifndef __WINDOW_H___
#define __WINDOW_H___
#include "graphics_helpers.h"
#include <stdlib.h>

typedef struct window window_t;

window_t* create_window(int width, int height, const char* window_name);
int should_window_close(window_t* window);
void clean_up_window(window_t* window);
int get_window_width(window_t* window);
int get_window_height(window_t* window);
float get_window_x_scale(window_t* window);
float get_window_y_scale(window_t* window);
GLFWwindow* get_window(window_t* window);
void swap_buffers(window_t* window);

#endif /* __WINDOW_H__ */
