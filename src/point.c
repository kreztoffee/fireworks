#include "point.h"
#include <stdlib.h>

struct point* create_point(float x, float y) {
	struct point* point = (struct point*) malloc(sizeof(struct point));
	point->x = x;
	point->y = y;
	return point;
}
