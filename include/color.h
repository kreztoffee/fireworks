#ifndef __COLOR_H__
#define __COLOR_H__

#include <stdint.h>

struct color {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
};

void set_random_color(struct color* col);

#endif /* __COLOR_H__ */
