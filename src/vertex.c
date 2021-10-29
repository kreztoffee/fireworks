#include "vertex.h"
#include <stdlib.h>

struct vertex* alloc_vertex() {
	return (struct vertex*) malloc(sizeof(struct vertex));
}

void free_vertex(struct vertex* vert) {
	free(vert);
}

struct vertex* make_vertex(struct point* pos, struct color* col) {
	struct vertex* vert = alloc_vertex();
	vert->x = pos->x;
	vert->y = pos->y;
	vert->r = col->r;
	vert->g = col->g;
	vert->b = col->b;
	vert->a = col->a;
	return vert;
}
