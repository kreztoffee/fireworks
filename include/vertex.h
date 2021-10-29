#ifndef __VERTEX_H__
#define __VERTEX_H__

#include <stdint.h>

struct vertex {
	float x, y;
	uint8_t r, g, b, a;
};

struct vertex* alloc_vertex();

#endif /* __VERTEX_H__ */
