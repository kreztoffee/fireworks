#ifndef __MOUSE_HANDLER_H__
#define __MOUSE_HANDLER_H__

#include "window.h"
#include <stdio.h>

void init_mouse_handler(window_t *window);
void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);

#endif /* __MOUSE_HANDLER_H__ */
