#ifndef __KEYBOARD_HANDLER_H__
#define __KEYBOARD_HANDLER_H__

#include "window.h"
#include <stdio.h>

void init_keyboard_handler(window_t *window);
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

#endif /* __KEYBOARD_HANDLER_H__ */
