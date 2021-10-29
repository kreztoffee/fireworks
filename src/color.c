#include "color.h"
#include <stdlib.h>

void set_random_color(struct color* col) {
	col->r = rand() % 255;
	col->g = rand() % 255;
	col->b = rand() % 255;
}
